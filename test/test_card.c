#include "cfaker.h"
#include "providers/cfaker_card.h"
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

static int test_card_pan() {
    const char* result = cfaker_card_pan();
    return check_string("cfaker_card_pan", result);
}

static int test_card_cvv2() {
    const char* result = cfaker_card_cvv2();
    return check_string("cfaker_card_cvv2", result);
}

static int test_card_issuer() {
    const char* result = cfaker_card_issuer();
    return check_string("cfaker_card_issuer", result);
}

int main() {
    // Initialize cfaker
    if (cfaker_init() != 0) {
        printf("FAIL: cfaker_init failed\n");
        return 1;
    }

    int failures = 0;
    printf("Testing cfaker_card module...\n");
    failures += test_card_pan();
    failures += test_card_cvv2();
    failures += test_card_issuer();

    // Clean up
    cfaker_free();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
