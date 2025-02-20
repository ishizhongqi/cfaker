#include "cfaker_random.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static _Thread_local char* buffer = NULL;    /* Thread-local storage for random strings */
static _Thread_local size_t buffer_size = 0; /* Buffer size */

static _Thread_local const char** elements_buffer = NULL; /* Thread-local storage for random elements */
static _Thread_local size_t elements_buffer_size = 0;     /* Buffer size */

static _Thread_local const char** elements_duplicate = NULL;
static _Thread_local size_t elements_duplicate_size = 0;

static _Thread_local uint32_t mt19937_state[624]; /* Mersenne Twister state */
static _Thread_local int mt19937_index = 0;       /* Index for the state */

/* Generate a random 32-bit integer */
static uint32_t mt19937_generate() {
    if (mt19937_index == 0) {
        for (int i = 0; i < 624; i++) {
            uint32_t y = (mt19937_state[i] & 0x80000000) + (mt19937_state[(i + 1) % 624] & 0x7fffffff);
            mt19937_state[i] = mt19937_state[(i + 397) % 624] ^ (y >> 1);
            if (y % 2 != 0) {
                mt19937_state[i] ^= 0x9908b0df;
            }
        }
    }
    uint32_t y = mt19937_state[mt19937_index];
    mt19937_index = (mt19937_index + 1) % 624;
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680;
    y ^= (y << 15) & 0xefc60000;
    y ^= (y >> 18);
    return y;
}

int cfaker_random_init(size_t size) {
    if (buffer == NULL) {                            /* If the buffer is not initialized */
        buffer = (char*)malloc(size * sizeof(char)); /* Allocate memory for the buffer */
        if (!buffer) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        buffer_size = size;
    }

    if (elements_buffer == NULL) { /* If the buffer is not initialized */
        elements_buffer = malloc(size * sizeof(char*));
        if (!elements_buffer) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        elements_buffer_size = size;
    }

    if (elements_duplicate == NULL) { /* If the buffer is not initialized */
        elements_duplicate = malloc(size * sizeof(char*));
        if (!elements_duplicate) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        elements_duplicate_size = size;
    }

    unsigned int seed = (unsigned int)time(NULL) + getpid();
    mt19937_state[0] = seed;
    for (int i = 1; i < 624; i++) {
        mt19937_state[i] = (1812433253 * (mt19937_state[i - 1] ^ (mt19937_state[i - 1] >> 30)) + i);
    }

    return 0;
}

uint32_t cfaker_random_int(uint32_t min, uint32_t max) {
    uint32_t random_value = mt19937_generate();
    return (random_value % (max - min + 1)) + min;
}

uint32_t cfaker_random_digit() {
    return cfaker_random_int(0, 9);
}

uint32_t cfaker_random_digit_non_zero() {
    return cfaker_random_int(1, 9);
}

uint32_t cfaker_random_digit_above_two() {
    return cfaker_random_int(2, 9);
}

char cfaker_random_digit_or_empty() {
    return cfaker_random_int(0, 1) ? ('0' + cfaker_random_digit()) : ' ';
}

char cfaker_random_digit_non_zero_or_empty() {
    return cfaker_random_int(0, 1) ? ('0' + cfaker_random_digit_non_zero()) : ' ';
}

char cfaker_random_hexchar() {
    return (char)(cfaker_random_int(0, 15) < 10 ? '0' + cfaker_random_int(0, 9) : 'a' + cfaker_random_int(0, 5));
}

char cfaker_random_lowercase_letter() {
    return (char)cfaker_random_int(97, 122);
}

char cfaker_random_uppercase_letter() {
    return (char)cfaker_random_int(65, 90);
}

char cfaker_random_letter() {
    if (cfaker_random_int(0, 1)) {
        /* a~z */
        return cfaker_random_lowercase_letter();
    } else {
        /* A~Z */
        return cfaker_random_uppercase_letter();
    }
}

char* cfaker_random_letters(uint32_t size) {
    if (size > buffer_size) {
        buffer = realloc(buffer, size * sizeof(char) + 1);
    }
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (uint32_t i = 0; i < size; i++) {
        buffer[i] = cfaker_random_letter();
    }
    buffer[size] = '\0';
    return buffer;
}

const char** cfaker_random_elements(const char** elements, size_t count, size_t length, int unique) {
    if (count == 0)
        return NULL;

    /* 若 length 为 0，则随机决定返回多少个元素（至少 1 个，最多 count 个） */
    if (length == 0) {
        length = cfaker_random_int(1, count);
    }

    /* 如果要求唯一抽样，但 requested length 大于可选元素个数，则报错 */
    if (unique && length > count) {
        fprintf(stderr, "Error: requested unique sample length exceeds available elements.\n");
        return NULL;
    }

    /* 分配存储结果的数组 */
    if (length > elements_buffer_size) {
        elements_buffer = realloc(elements_buffer, length * sizeof(char*));
        if (!elements_buffer) {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        elements_buffer_size = length;
    }

    if (!unique) {
        /* 有放回抽样：每次都从所有元素中随机选取 */
        for (size_t i = 0; i < length; i++) {
            elements_buffer[i] = elements[cfaker_random_int(0, count - 1)];
        }
    } else {
        /* 无放回抽样：使用 Fisher-Yates 洗牌算法 */
        /* 先复制一份原始数组到临时数组 */
        if (count > elements_duplicate_size) {
            elements_duplicate = realloc(elements_duplicate, count * sizeof(char*));
            if (!elements_duplicate) {
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
            elements_duplicate_size = count;
        }
        memcpy(elements_duplicate, elements, count * sizeof(char*));

        /* 洗牌：从后向前随机交换 */
        for (size_t i = count - 1; i > 0; i--) {
            size_t j = cfaker_random_int(0, i);
            const char* swap = elements_duplicate[i];
            elements_duplicate[i] = elements_duplicate[j];
            elements_duplicate[j] = swap;
        }
        /* 取前 length 个元素 */
        for (size_t i = 0; i < length; i++) {
            elements_buffer[i] = elements_duplicate[i];
        }
    }
    return elements_buffer;
}

const char** cfaker_random_choices(const char** elements, size_t count, size_t length) {
    return cfaker_random_elements(elements, count, length, 0);
}

const char* cfaker_random_element(const char** elements, size_t count) {
    const char** res = cfaker_random_elements(elements, count, 1, 0);
    const char* elem = res[0];
    return elem;
}

const char** cfaker_random_sample(const char** elements, size_t count, size_t length) {
    return cfaker_random_elements(elements, count, length, 1);
}

int cfaker_random_randomize(int number, int le, int ge, int min_val, int max_val) {
    /* 根据给定的 number，生成一个随机数量，该值大致在某个比例范围内。
     * 参数：
     *   number: 基准数字
     *   le: 如果为非0，表示上界限定为 100%（否则可上升至 140%）
     *   ge: 如果为非0，表示下界限定为 100%（否则可下降至 60%）
     *   min_val: 若不希望结果低于某个值（若无此限制，可传 -1）
     *   max_val: 若不希望结果高于某个值（若无此限制，可传 -1）
     */
    /* 如果同时要求上界和下界都为 100%，则直接返回原数 */
    if (le && ge) {
        return number;
    }
    int lower_percentage = ge ? 100 : 60;
    int upper_percentage = le ? 100 : 140;
    int percentage = cfaker_random_int(lower_percentage, upper_percentage);
    int nb = number * percentage / 100;
    if (min_val != -1 && nb < min_val) {
        nb = min_val;
    }
    if (max_val != -1 && nb > max_val) {
        nb = max_val;
    }
    return nb;
}

time_t cfaker_random_timestamp(const char* start, const char* end) {
    struct tm tm_start = { 0 }, tm_end = { 0 };
    time_t start_time, end_time;

    // Use sscanf to parse the datetime string manually
    if (sscanf(start, "%d-%d-%d %d:%d:%d", &tm_start.tm_year, &tm_start.tm_mon, &tm_start.tm_mday, &tm_start.tm_hour,
               &tm_start.tm_min, &tm_start.tm_sec)
            != 6
        || sscanf(end, "%d-%d-%d %d:%d:%d", &tm_end.tm_year, &tm_end.tm_mon, &tm_end.tm_mday, &tm_end.tm_hour,
                  &tm_end.tm_min, &tm_end.tm_sec)
               != 6) {
        return (time_t)0;
    }

    tm_start.tm_year -= 1900;  // Years since 1900
    tm_start.tm_mon -= 1;      // Months are 0-based
    tm_end.tm_year -= 1900;
    tm_end.tm_mon -= 1;

    // Convert to time_t
    start_time = mktime(&tm_start);
    end_time = mktime(&tm_end);

    // Generate a random timestamp between start_time and end_time
    return cfaker_random_int(start_time, end_time);
}

void cfaker_random_free() {
    if (buffer != NULL) {
        free(buffer);
        buffer = NULL;
        buffer_size = 0;
    }

    if (elements_buffer != NULL) {
        free(elements_buffer);
        elements_buffer = NULL;
        elements_buffer_size = 0;
    }

    if (elements_duplicate != NULL) {
        free(elements_duplicate);
        elements_duplicate = NULL;
        elements_duplicate_size = 0;
    }
}
