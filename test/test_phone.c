#include "providers/cfaker_phone.h"
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

static int test_phone_code() {
    const char* result = cfaker_phone_code(true);
    return check_string("cfaker_phone_code", result);
}

static int test_phone_number() {
    const char* result = cfaker_phone_number();
    return check_string("cfaker_phone_number", result);
}

int main() {
    int failures = 0;
    printf("Testing cfaker_phone module...\n");
    failures += test_phone_code();
    failures += test_phone_number();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
