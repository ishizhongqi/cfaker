#include "providers/cfaker_book.h"
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

static int test_book_title() {
    const char* result = cfaker_book_title();
    return check_string("cfaker_book_title", result);
}

static int test_book_author() {
    const char* result = cfaker_book_author();
    return check_string("cfaker_book_author", result);
}

int main() {
    int failures = 0;
    printf("Testing cfaker_book module...\n");
    failures += test_book_title();
    failures += test_book_author();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
