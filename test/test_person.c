#include "providers/cfaker_person.h"
#include <stdio.h>
#include <string.h>

// 测试辅助函数：检查字符串是否非空并打印结果
static int check_string(const char* func_name, const char* result) {
    if (result == NULL || strlen(result) == 0) {
        printf("FAIL: %s returned NULL or empty string\n", func_name);
        return 1;  // 失败
    }
    printf("PASS: %s returned '%s'\n", func_name, result);
    return 0;  // 成功
}

// 测试 cfaker_person_first_name
static int test_first_name() {
    int failures = 0;
    const char* female_name = cfaker_person_first_name(CFAKER_PERSON_FEMALE);
    const char* male_name = cfaker_person_first_name(CFAKER_PERSON_MALE);
    const char* any_name = cfaker_person_first_name(CFAKER_PERSON_ANY);

    failures += check_string("cfaker_person_first_name(FEMALE)", female_name);
    failures += check_string("cfaker_person_first_name(MALE)", male_name);
    failures += check_string("cfaker_person_first_name(ANY)", any_name);

    return failures;
}

// 测试 cfaker_person_last_name
static int test_last_name() {
    const char* last_name = cfaker_person_last_name();
    return check_string("cfaker_person_last_name", last_name);
}

// 测试 cfaker_person_prefix
static int test_prefix() {
    int failures = 0;
    const char* female_prefix = cfaker_person_prefix(CFAKER_PERSON_FEMALE);
    const char* male_prefix = cfaker_person_prefix(CFAKER_PERSON_MALE);
    const char* any_prefix = cfaker_person_prefix(CFAKER_PERSON_ANY);

    failures += check_string("cfaker_person_prefix(FEMALE)", female_prefix);
    failures += check_string("cfaker_person_prefix(MALE)", male_prefix);
    failures += check_string("cfaker_person_prefix(ANY)", any_prefix);

    return failures;
}

// 测试 cfaker_person_suffix
static int test_suffix() {
    int failures = 0;
    const char* female_suffix = cfaker_person_suffix(CFAKER_PERSON_FEMALE);
    const char* male_suffix = cfaker_person_suffix(CFAKER_PERSON_MALE);
    const char* any_suffix = cfaker_person_suffix(CFAKER_PERSON_ANY);

    failures += check_string("cfaker_person_suffix(FEMALE)", female_suffix);
    failures += check_string("cfaker_person_suffix(MALE)", male_suffix);
    failures += check_string("cfaker_person_suffix(ANY)", any_suffix);

    return failures;
}

// 测试 cfaker_person_full_name
static int test_full_name() {
    int failures = 0;
    const char* female_full = cfaker_person_full_name(CFAKER_PERSON_FEMALE);
    const char* male_full = cfaker_person_full_name(CFAKER_PERSON_MALE);
    const char* any_full = cfaker_person_full_name(CFAKER_PERSON_ANY);

    failures += check_string("cfaker_person_full_name(FEMALE)", female_full);
    failures += check_string("cfaker_person_full_name(MALE)", male_full);
    failures += check_string("cfaker_person_full_name(ANY)", any_full);

    return failures;
}

// 主测试函数
int main() {
    int failures = 0;

    printf("Testing cfaker_person module...\n");
    failures += test_first_name();
    failures += test_last_name();
    failures += test_prefix();
    failures += test_suffix();
    failures += test_full_name();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }

    return failures > 0 ? 1 : 0;  // 返回非零表示失败，供 CTest 使用
}
