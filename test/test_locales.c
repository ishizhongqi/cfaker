#include "cfaker_locale.h"
#include <stdio.h>

static int check_locale_set(enum cfaker_locale set_locale, const char* func_name) {
    cfaker_locale_set(set_locale);
    enum cfaker_locale current = cfaker_locale_get();
    if (current != set_locale) {
        printf("FAIL: %s set %d, got %d\n", func_name, set_locale, current);
        return 1;
    }
    printf("PASS: %s set and got %d\n", func_name, set_locale);
    return 0;
}

static int check_locale_set_bystring(const char* locale_str, enum cfaker_locale expected, const char* func_name) {
    cfaker_locale_set_bystring(locale_str);
    enum cfaker_locale current = cfaker_locale_get();
    if (current != expected) {
        printf("FAIL: %s set '%s', expected %d, got %d\n", func_name, locale_str, expected, current);
        return 1;
    }
    printf("PASS: %s set '%s', got %d\n", func_name, locale_str, current);
    return 0;
}

static int test_locale_set() {
    int failures = 0;
    failures += check_locale_set(en_US, "cfaker_locale_set(en_US)");
    failures += check_locale_set(zh_CN, "cfaker_locale_set(zh_CN)");
    return failures;
}

static int test_locale_set_bystring() {
    int failures = 0;
    failures += check_locale_set_bystring("en_US", en_US, "cfaker_locale_set_bystring(en_US)");
    failures += check_locale_set_bystring("zh_CN", zh_CN, "cfaker_locale_set_bystring(zh_CN)");
    return failures;
}

static int test_locale_get() {
    cfaker_locale_set(en_US);
    enum cfaker_locale current = cfaker_locale_get();
    if (current != en_US) {
        printf("FAIL: cfaker_locale_get expected %d, got %d\n", en_US, current);
        return 1;
    }
    printf("PASS: cfaker_locale_get returned %d\n", current);
    return 0;
}

int main() {
    int failures = 0;
    printf("Testing cfaker_locales module...\n");
    failures += test_locale_set();
    failures += test_locale_set_bystring();
    failures += test_locale_get();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
