#include "cfaker_format.h"
#include "cfaker_random.h"

#include <inttypes.h>
#include <stdio.h>

#if defined(_WIN32)
#include <windows.h>
#else
#include <sys/time.h>
#endif

/* Helper: Get current time in 100-nanosecond intervals since 1582-10-15 */
static uint64_t get_time_v1() {
    uint64_t epoch_1582 = 122192928000000000ULL;  // 1582-10-15到1970-01-01的100纳秒间隔

#if defined(_WIN32)
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    uint64_t time = ((uint64_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
    return time + epoch_1582;  // 已经是自1601-01-01以来的100纳秒间隔
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    const uint64_t unix_ns = (uint64_t)tv.tv_sec * 10000000ULL + tv.tv_usec * 10;
    return unix_ns + epoch_1582;
#endif
}

/* Helper: Fake MAC address (random) */
static void get_fake_mac(uint8_t* mac) {
    for (int i = 0; i < 6; i++) {
        mac[i] = (uint8_t)cfaker_random_uint(0, 255);
    }
}

const char* cfaker_uuid_v1() {
    const uint64_t time = get_time_v1();
    const uint16_t clock_seq = (uint16_t)cfaker_random_uint(0, 0x3FFF);  // 14位
    uint8_t mac[6];
    get_fake_mac(mac);

    const uint32_t time_low = (uint32_t)(time & 0xFFFFFFFF);
    const uint16_t time_mid = (uint16_t)((time >> 32) & 0xFFFF);
    const uint16_t time_hi = (uint16_t)((time >> 48) & 0x0FFF) | (1 << 12);  // 版本1

    char uuid[37];
    snprintf(uuid, sizeof(uuid), "%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x", time_low, time_mid, time_hi,
             (clock_seq & 0x3FFF) | 0x8000,  // 变体10xx
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return cfaker_format_replace_string(uuid, NULL, 0);  // 复制到cfaker缓冲区
}

const char* cfaker_uuid_v4() {
    const uint32_t rand1 = cfaker_random_uint(0, 0xFFFFFFFF);                  // 32位
    const uint16_t rand2 = (uint16_t)cfaker_random_uint(0, 0xFFFF);            // 16位
    const uint16_t rand3 = (cfaker_random_uint(0, 0xFFF) & 0x0FFF) | 0x4000;   // 16位，版本4
    const uint16_t rand4 = (cfaker_random_uint(0, 0x3FFF) & 0x3FFF) | 0x8000;  // 16位，变体10xx
    const uint64_t rand5 = ((uint64_t)cfaker_random_uint(0, 0xFFFF) << 32) | cfaker_random_uint(0, 0xFFFFFFFF);  // 48位

    char uuid[37];
    snprintf(uuid, sizeof(uuid), "%08" PRIx32 "-%04x-%04x-%04x-%012" PRIx64, rand1, rand2, rand3, rand4, rand5);
    return cfaker_format_replace_string(uuid, NULL, 0);
}

const char* cfaker_uuid_v7() {
#if defined(_WIN32)
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    uint64_t win_time = ((uint64_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
    // 将Windows时间（自1601-01-01以来的100纳秒）转换为Unix时间（自1970-01-01以来的毫秒）
    uint64_t epoch_diff = 116444736000000000ULL;         // 1601-01-01到1970-01-01的100纳秒间隔
    uint64_t unix_ms = (win_time - epoch_diff) / 10000;  // 转换为毫秒
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    uint64_t unix_ms = (uint64_t)tv.tv_sec * 1000ULL + tv.tv_usec / 1000ULL;
#endif

    const uint32_t time_high = (uint32_t)(unix_ms >> 16);                         // 32位
    const uint16_t time_low = (uint16_t)(unix_ms & 0xFFFF);                       // 16位
    const uint16_t rand_a = (cfaker_random_uint(0, 0xFFF) & 0x0FFF) | (7 << 12);  // 12位随机数 + 版本7
    const uint16_t rand_b = (cfaker_random_uint(0, 0xFFFF) & 0x3FFF) | 0x8000;    // 14位随机数 + 变体10xx
    const uint64_t rand_c = ((uint64_t)cfaker_random_uint(0, 0xFFFF) << 32) | cfaker_random_uint(0, 0xFFFFFFFF);  // 48位

    char uuid[37];
    snprintf(uuid, sizeof(uuid), "%08x-%04x-%04x-%04x-%012" PRIx64, time_high, time_low, rand_a, rand_b, rand_c);
    return cfaker_format_replace_string(uuid, NULL, 0);
}
