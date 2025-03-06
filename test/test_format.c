#include "cfaker.h"
#include "cfaker_format.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int check_string(const char* func_name, const char* result) {
    if (result == NULL || strlen(result) == 0) {
        printf("FAIL: %s returned NULL or empty string\n", func_name);
        return 1;
    }
    printf("PASS: %s returned '%s'\n", func_name, result);
    return 0;
}

static int test_replace_string() {
    struct cfaker_format_mapping mappings[] = { { "firstname", "John" }, { "lastname", "Doe" } };
    const char* result = cfaker_format_replace_string("{firstname} {lastname}", mappings, 2);
    int failures = check_string("cfaker_format_replace_string", result);
    if (!failures && strcmp(result, "John Doe") != 0) {
        printf("FAIL: Expected 'John Doe', got '%s'\n", result);
        failures++;
    }
    return failures;
}

static int test_replace_numbers() {
    const char* result = cfaker_format_replace_numbers("###-###-####");
    return check_string("cfaker_format_replace_numbers", result);
}

static int test_replace_letters() {
    const char* result = cfaker_format_replace_letters("?11?-abc", NULL);
    return check_string("cfaker_format_replace_letters", result);
}

int main() {
    // Initialize cfaker
    if (cfaker_init() != 0) {
        printf("FAIL: cfaker_init failed\n");
        return 1;
    }

    int failures = 0;
    printf("Testing cfaker_format module...\n");
    failures += test_replace_string();
    failures += test_replace_numbers();
    failures += test_replace_letters();

    // Clean up
    cfaker_free();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
