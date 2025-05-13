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

static int check_int_range(const char* func_name, int32_t value, int32_t min, int32_t max) {
    if (value < min || value > max) {
        printf("FAIL: %s returned %d, out of range [%d, %d]\n", func_name, value, min, max);
        return 1;
    }
    printf("PASS: %s returned %d\n", func_name, value);
    return 0;
}

static int test_internet_tlds() {
    const char* result = cfaker_internet_tlds();
    return check_string("cfaker_internet_tlds", result);
}

static int test_internet_domain() {
    const char* result = cfaker_internet_domain(1);
    return check_string("cfaker_internet_domain", result);
}

static int test_internet_username() {
    const char* result = cfaker_internet_username();
    return check_string("cfaker_internet_username", result);
}

static int test_internet_password() {
    int length = 10;
    uint8_t char_flags =
        CFAKER_INTERNET_LOWERCASE | CFAKER_INTERNET_UPPERCASE | CFAKER_INTERNET_NUMBER | CFAKER_INTERNET_SPECIAL;
    const char* result = cfaker_internet_password(length, char_flags);
    return check_string("cfaker_internet_password", result);
}

static int test_internet_email() {
    const char* result = cfaker_internet_email(NULL);
    return check_string("cfaker_internet_email", result);
}

static int test_internet_url() {
    const char* schemes = "http,https";
    const char* result = cfaker_internet_url(schemes);
    return check_string("cfaker_internet_url", result);
}

static int test_internet_ipv4() {
    const char* result = cfaker_internet_ipv4();
    return check_string("cfaker_internet_ipv4", result);
}

static int test_internet_ipv6() {
    const char* result = cfaker_internet_ipv6();
    return check_string("cfaker_internet_ipv6", result);
}

static int test_internet_mac() {
    const char* result = cfaker_internet_mac();
    return check_string("cfaker_internet_mac", result);
}

static int test_internet_port() {
    uint16_t result = cfaker_internet_port();
    return check_int_range("cfaker_internet_port", result, 0, 65535);
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
    failures += test_internet_email();
    failures += test_internet_url();
    failures += test_internet_ipv4();
    failures += test_internet_ipv6();
    failures += test_internet_mac();
    failures += test_internet_port();

    // Clean up
    cfaker_free();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
