#include "providers/cfaker_number.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// 检查整数范围
static int check_int_range(const char* func_name, int32_t value, int32_t min, int32_t max) {
    if (value < min || value > max) {
        printf("FAIL: %s returned %d, out of range [%d, %d]\n", func_name, value, min, max);
        return 1;
    }
    printf("PASS: %s returned %d\n", func_name, value);
    return 0;
}

// 检查浮点范围
static int check_double_range(const char* func_name, double value, double min, double max) {
    if (value < min || value > max) {
        printf("FAIL: %s returned %f, out of range [%f, %f]\n", func_name, value, min, max);
        return 1;
    }
    printf("PASS: %s returned %f\n", func_name, value);
    return 0;
}

// 检查字符串非空
static int check_string(const char* func_name, const char* result) {
    if (result == NULL || strlen(result) == 0) {
        printf("FAIL: %s returned NULL or empty string\n", func_name);
        return 1;
    }
    printf("PASS: %s returned '%s'\n", func_name, result);
    return 0;
}

// 测试 cfaker_number_int
static int test_number_int() {
    int32_t value = cfaker_number_int(10, 20);
    return check_int_range("cfaker_number_int", value, 10, 20);
}

// 测试 cfaker_number_double
static int test_number_double() {
    double value = cfaker_number_double(1.5, 3.5);
    return check_double_range("cfaker_number_double", value, 1.5, 3.5);
}

// 测试 cfaker_number_hexadecimal_bylength
static int test_hexadecimal_bylength() {
    const char* result = cfaker_number_hexadecimal_bylength(4, true, CFAKER_NUMBER_HEX_HASH);
    return check_string("cfaker_number_hexadecimal_bylength", result);
}

// 测试 cfaker_number_hexadecimal_byrange
static int test_hexadecimal_byrange() {
    const char* result = cfaker_number_hexadecimal_byrange(100, 500);
    return check_string("cfaker_number_hexadecimal_byrange", result);
}

// 测试 cfaker_number_octal_byrange
static int test_octal_byrange() {
    const char* result = cfaker_number_octal_byrange(10, 50);
    return check_string("cfaker_number_octal_byrange", result);
}

// 测试 cfaker_number_binary_byrange
static int test_binary_byrange() {
    const char* result = cfaker_number_binary_byrange(5, 20);
    return check_string("cfaker_number_binary_byrange", result);
}

int main() {
    int failures = 0;
    printf("Testing cfaker_number module...\n");
    failures += test_number_int();
    failures += test_number_double();
    failures += test_hexadecimal_bylength();
    failures += test_hexadecimal_byrange();
    failures += test_octal_byrange();
    failures += test_binary_byrange();

    if (failures == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Tests failed: %d failures\n", failures);
    }
    return failures > 0 ? 1 : 0;
}
