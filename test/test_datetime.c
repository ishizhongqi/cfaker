#include "providers/cfaker_datetime.h"
#include <stdio.h>
#include <string.h>

static int check_uint_range(const char* func_name, unsigned int value, unsigned int min, unsigned int max) {
    if (value < min || value > max) {
        printf("FAIL: %s returned %u, out of range [%u, %u]\n", func_name, value, min, max);
        return 1;
    }
    printf("PASS: %s returned %u\n", func_name, value);
    return 0;
}

static int check_string(const char* func_name, const char* result) {
    if (result == NULL || strlen(result) == 0) {
        printf("FAIL: %s returned NULL or empty string\n", func_name);
        return 1;
    }
    printf("PASS: %s returned '%s'\n", func_name, result);
    return 0;
}

static int test_timestamp() {
    time_t result = cfaker_datetime_timestamp("2020-01-01", "2025-12-31");
    if (result == (time_t)-1) {
        printf("FAIL: cfaker_datetime_timestamp returned invalid timestamp\n");
        return 1;
    }
    printf("PASS: cfaker_datetime_timestamp returned %ld\n", (long)result);
    return 0;
}

static int test_datetime() {
    const char* result = cfaker_datetime_datetime("%Y-%m-%d", "2020-01-01", "2025-12-31");
    return check_string("cfaker_datetime_datetime", result);
}

static int test_month_name() {
    const char* full = cfaker_datetime_month_name(CFAKER_DATETIME_FULL);
    const char* abbr = cfaker_datetime_month_name(CFAKER_DATETIME_ABBREVIATED);
    int failures = 0;
    failures += check_string("cfaker_datetime_month_name(FULL)", full);
    failures += check_string("cfaker_datetime_month_name(ABBREVIATED)", abbr);
    return failures;
}

static int test_weekday_name() {
    const char* full = cfaker_datetime_weekday_name(CFAKER_DATETIME_FULL);
    const char* abbr = cfaker_datetime_weekday_name(CFAKER_DATETIME_ABBREVIATED);
    int failures = 0;
    failures += check_string("cfaker_datetime_weekday_name(FULL)", full);
    failures += check_string("cfaker_datetime_weekday_name(ABBREVIATED)", abbr);
    return failures;
}

int main() {
    int failures = 0;
    printf("Testing cfaker_datetime module...\n");
    failures += test_timestamp();
    failures += test_datetime();
    failures += test_month_name();
    failures += test_weekday_name();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
