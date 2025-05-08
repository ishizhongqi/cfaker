#include "cfaker.h"
#include "providers/cfaker_internet.h"
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

static int test_internet_tlds() {
    const char* result = cfaker_internet_tlds();
    return check_string("cfaker_internet_tlds", result);
}

static int test_internet_domain() {
    // const char* result = cfaker_internet_domain(2);
    // return check_string("cfaker_internet_domain", result);
    return 0;
}

static int test_internet_username() {
    const char* result = cfaker_internet_username();
    return check_string("cfaker_internet_username", result);
}

static int test_internet_password() {
    int length = 10;
    uint8_t char_flags =
        CFAKER_INTERNET_LOWERLETTER | CFAKER_INTERNET_UPPERLETTER | CFAKER_INTERNET_NUMBER | CFAKER_INTERNET_SPECIAL;
    const char* result = cfaker_internet_password(length, char_flags);
    return check_string("cfaker_internet_password", result);
}

int main() {
    // Initialize cfaker
    if (cfaker_init() != 0) {
        printf("FAIL: cfaker_init failed\n");
        return 1;
    }

    int failures = 0;
    printf("Testing cfaker_internet module...\n");
    failures += test_internet_tlds();
    failures += test_internet_domain();
    failures += test_internet_username();
    failures += test_internet_password();

    // Clean up
    cfaker_free();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
