#include "providers/cfaker_bank.h"
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

static int test_bank_name() {
    const char* result = cfaker_bank_name();
    return check_string("cfaker_bank_name", result);
}

int main() {
    int failures = 0;
    printf("Testing cfaker_bank module...\n");
    failures += test_bank_name();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
