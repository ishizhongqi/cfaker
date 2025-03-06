#include "cfaker.h"
#include "providers/cfaker_uuid.h"
#include <stdio.h>
#include <string.h>

static int check_string(const char* func_name, const char* result) {
    if (result == NULL || strlen(result) == 0) {
        printf("FAIL: %s returned NULL or empty string\n", func_name);
        return 1;
    }
    // Basic UUID format check: 36 chars (32 hex + 4 hyphens)
    if (strlen(result) != 36 || result[8] != '-' || result[13] != '-' || result[18] != '-' || result[23] != '-') {
        printf("FAIL: %s returned '%s', invalid UUID format\n", func_name, result);
        return 1;
    }
    printf("PASS: %s returned '%s'\n", func_name, result);
    return 0;
}

static int test_uuid_v1() {
    const char* result = cfaker_uuid_v1();
    int fail = check_string("cfaker_uuid_v1", result);
    // Check version (should be 1 at position 14)
    if (!fail && result[14] != '1') {
        printf("FAIL: %s version is not 1, got '%c'\n", "cfaker_uuid_v1", result[14]);
        return 1;
    }
    return fail;
}

static int test_uuid_v4() {
    const char* result = cfaker_uuid_v4();
    int fail = check_string("cfaker_uuid_v4", result);
    // Check version (should be 4 at position 14)
    if (!fail && result[14] != '4') {
        printf("FAIL: %s version is not 4, got '%c'\n", "cfaker_uuid_v4", result[14]);
        return 1;
    }
    return fail;
}

static int test_uuid_v7() {
    const char* result = cfaker_uuid_v7();
    int fail = check_string("cfaker_uuid_v7", result);
    // Check version (should be 7 at position 14)
    if (!fail && result[14] != '7') {
        printf("FAIL: %s version is not 7, got '%c'\n", "cfaker_uuid_v7", result[14]);
        return 1;
    }
    return fail;
}

int main() {
    // Initialize cfaker
    if (cfaker_init() != 0) {
        printf("FAIL: cfaker_init failed\n");
        return 1;
    }

    int failures = 0;
    printf("Testing cfaker_uuid module...\n");

    // Initialize cfaker
    if (cfaker_init() != 0) {
        printf("FAIL: cfaker_init failed\n");
        return 1;
    }

    failures += test_uuid_v1();
    failures += test_uuid_v4();
    failures += test_uuid_v7();

    // Clean up
    cfaker_free();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
