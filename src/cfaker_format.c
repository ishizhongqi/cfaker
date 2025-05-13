#include "cfaker_format.h"

#include "cfaker_random.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static _Thread_local char* buffer = NULL;    /* Thread-local storage for random strings */
static _Thread_local size_t buffer_size = 0; /* Buffer size */

/* Calculates the required buffer size for formatted output */
static size_t calculate_mappings_size(const char* format, const struct cfaker_format_mapping* mappings,
                                      const size_t mapping_count) {
    size_t size = 1; /* Start with 1 for the null terminator */

    const char* ptr = format;
    while (*ptr) {
        if (*ptr == '{') {
            const char* end = strchr(ptr, '}');
            if (end) {
                size_t token_len = end - ptr - 1;
                char* token = malloc(token_len + 1);
                strncpy(token, ptr + 1, token_len);
                token[token_len] = '\0';

                const char* replacement = NULL;
                for (size_t i = 0; i < mapping_count; i++) {
                    if (strcmp(mappings[i].token, token) == 0) {
                        replacement = mappings[i].value;
                        break;
                    }
                }

                free(token);
                token = NULL;

                if (replacement) {
                    size += strlen(replacement);
                } else {
                    size += (token_len + 2); /* Keep original token if not found */
                }
                ptr = end + 1;
                continue;
            }
        }
        size++;
        ptr++;
    }
    return size;
}

static size_t calculate_datetime_size(const char* format) {
    size_t size = 1; /* Start with 1 for the null terminator */
    const char* ptr = format;

    while (*ptr) {
        if (*ptr == '%') {
            ptr++;  // Skip '%' symbol
            switch (*ptr) {
            case 'Y':  // 4 digits for year
                size += 4;
                break;
            case 'm':  // 2 digits for month
            case 'd':  // 2 digits for day
            case 'H':  // 2 digits for hour
            case 'M':  // 2 digits for minute
            case 'S':  // 2 digits for second
                size += 2;
                break;
            default:
                size++;  // Add 1 for other format symbols
                break;
            }
        } else {
            size++;
        }
        ptr++;
    }
    return size;
}

static int update_buffer_size(const size_t size) {
    if (buffer_size < size) {
        buffer = realloc(buffer, size * sizeof(char));
        if (!buffer) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        buffer_size = size;
    }
    return 0;
}

int cfaker_format_init(const size_t size) {
    if (buffer == NULL) {
        buffer = (char*)malloc(size * sizeof(char));
        if (!buffer) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        buffer_size = size;
    }
    return 0;
}

const char* cfaker_format_replace_specifier(const char* format, ...) {
    va_list args;

    va_start(args, format);
    const int required_size = vsnprintf(NULL, 0, format, args);
    if (update_buffer_size(required_size) != 0) {
        return NULL;
    }
    va_end(args);

    va_start(args, format);
    vsnprintf(buffer, buffer_size, format, args);
    va_end(args);

    return buffer;
}

const char* cfaker_format_replace_string(const char* format, const struct cfaker_format_mapping* mappings,
                                         const size_t mapping_count) {
    const size_t required_size = calculate_mappings_size(format, mappings, mapping_count);

    if (update_buffer_size(required_size) != 0) {
        return NULL;
    }

    buffer[0] = '\0'; /* Clear the buffer */
    const char* ptr = format;

    while (*ptr) {
        if (*ptr == '{') {
            const char* end = strchr(ptr, '}');
            if (end) {
                size_t token_len = end - ptr - 1;
                char* token = malloc(token_len + 1);
                strncpy(token, ptr + 1, token_len);
                token[token_len] = '\0';

                const char* replacement = NULL;
                for (size_t i = 0; i < mapping_count; i++) {
                    if (strcmp(mappings[i].token, token) == 0) {
                        replacement = mappings[i].value;
                        break;
                    }
                }

                if (replacement) {
                    strcat(buffer, replacement);
                } else {
                    strcat(buffer, "{");
                    strcat(buffer, token);
                    strcat(buffer, "}");
                }

                free(token);
                token = NULL;

                ptr = end + 1;
                continue;
            }
        }
        strncat(buffer, ptr, 1);
        ptr++;
    }

    return buffer;
}

const char* cfaker_format_replace_numbers(const char* format) {
    const size_t len = strlen(format);
    if (update_buffer_size(len) != 0) {
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        if (format[i] == '#') {
            buffer[i] = '0' + cfaker_random_digit();
        } else if (format[i] == '%') {
            buffer[i] = '0' + cfaker_random_digit_non_zero();
        } else if (format[i] == '$') {
            buffer[i] = '0' + cfaker_random_digit_above_two();
        } else if (format[i] == '!') {
            buffer[i] = cfaker_random_digit_or_empty();
        } else if (format[i] == '@') {
            buffer[i] = cfaker_random_digit_non_zero_or_empty();
        } else {
            buffer[i] = format[i];
        }
    }
    buffer[len] = '\0';
    return buffer;
}

const char* cfaker_format_replace_letters(const char* format, const char* letters) {
    const size_t len = strlen(format);
    if (update_buffer_size(len) != 0) {
        return NULL;
    }

    if (letters == NULL) {
        for (size_t i = 0; i < len; i++) {
            buffer[i] = (format[i] == '?') ? cfaker_random_letter() : format[i];
        }
    } else {
        const size_t letters_len = strlen(letters);
        for (size_t i = 0; i < len; i++) {
            buffer[i] = (format[i] == '?') ? letters[cfaker_random_uint(0, letters_len - 1)] : format[i];
        }
    }

    buffer[len] = '\0';
    return buffer;
}

const char* cfaker_format_replace_chars(const char* format, const char* letters) {
    const size_t len = strlen(format);
    if (update_buffer_size(len) != 0) {
        return NULL;
    }
    return cfaker_format_replace_letters(cfaker_format_replace_numbers(format), letters);
}

const char* cfaker_format_replace_hexchars(const char* format, const bool upper) {
    const size_t len = strlen(format);
    if (update_buffer_size(len) != 0) {
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        buffer[i] =
            (format[i] == '^') ? (upper ? toupper(cfaker_random_hexchar()) : cfaker_random_hexchar()) : format[i];
    }
    buffer[len] = '\0';
    return buffer;
}

const char* cfaker_format_replace_datetime(const char* format, const char* start, const char* end) {
    const size_t required_size = calculate_datetime_size(format);
    if (update_buffer_size(required_size) != 0) {  // Resize buffer for larger possible result
        return NULL;
    }

    // Generate a random timestamp within the provided range
    const time_t random_timestamp = cfaker_random_timestamp(start, end);

    // Convert the random timestamp into a struct tm
    const struct tm* time_info = localtime(&random_timestamp);

    // Format the datetime using strftime
    strftime(buffer, buffer_size, format, time_info);

    return buffer;
}

void cfaker_format_free() {
    if (buffer != NULL && buffer_size != 0) {
        free(buffer);
        buffer = NULL;
        buffer_size = 0;
    }
}
