#include "cfaker.h"
#include "cfaker_random.h"
#include <stdio.h>
#include <string.h>

static int check_int_range(const char* func_name, int32_t value, int32_t min, int32_t max) {
    if (value < min || value > max) {
        printf("FAIL: %s returned %d, out of range [%d, %d]\n", func_name, value, min, max);
        return 1;
    }
    printf("PASS: %s returned %d\n", func_name, value);
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

static int test_random_int() {
    int32_t value = cfaker_random_int(10, 20);
    return check_int_range("cfaker_random_int", value, 10, 20);
}

static int test_random_letters() {
    char* result = cfaker_random_letters(5);
    int failures = check_string("cfaker_random_letters", result);
    if (!failures && strlen(result) != 5) {
        printf("FAIL: Expected length 5, got %zu\n", strlen(result));
        failures++;
    }
    return failures;
}

int main() {
    // Initialize cfaker
    if (cfaker_init() != 0) {
        printf("FAIL: cfaker_init failed\n");
        return 1;
    }

    int failures = 0;
    printf("Testing cfaker_random module...\n");
    failures += test_random_int();
    failures += test_random_letters();

    // Clean up
    cfaker_free();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
