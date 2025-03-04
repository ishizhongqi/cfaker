#include "cfaker.h"
#include <stdio.h>

static int test_init_free() {
    int result = cfaker_init();
    if (result != 0) {
        printf("FAIL: cfaker_init returned %d\n", result);
        return 1;
    }
    printf("PASS: cfaker_init succeeded\n");
    cfaker_free();
    return 0;
}

int main() {
    int failures = 0;
    printf("Testing cfaker module...\n");
    failures += test_init_free();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
