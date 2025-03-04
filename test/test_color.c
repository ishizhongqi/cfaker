#include "providers/cfaker_color.h"
#include <stdio.h>
#include <string.h>

static int check_string(const char* func_name, const char* result) {
    if (result == NULL || strlen(result) == 0) {
        printf("FAIL: %s returned NULL or empty string\n", func_name);
        return 1;
    }
    printf("PASS: %s returned '%s'\n", func_name, result);
    return 0;
}

static int test_color_name() {
    const char* result = cfaker_color_name();
    return check_string("cfaker_color_name", result);
}

static int test_color_rgb() {
    const char* result = cfaker_color_rgb(false);
    return check_string("cfaker_color_rgb", result);
}

static int test_color_hex() {
    const char* result = cfaker_color_hex(true, CFAKER_NUMBER_HEX_HASH, false);
    return check_string("cfaker_color_hex", result);
}

int main() {
    int failures = 0;
    printf("Testing cfaker_color module...\n");
    failures += test_color_name();
    failures += test_color_rgb();
    failures += test_color_hex();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
