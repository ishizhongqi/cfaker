#include "cfaker_format.h"
#include "cfaker_random.h"

#include "providers/cfaker_number.h"
#include "providers/data/cfaker_number_data.h"

#include <string.h>

int32_t cfaker_number_int(int32_t min, int32_t max) {
    return cfaker_random_int(min, max);
}

double cfaker_number_double(double min, double max) {
    return cfaker_random_double(min, max);
}

const char* cfaker_number_hexadecimal_bylength(uint32_t length, bool upper, enum cfaker_number_hex_prefix hex_prefix) {
    char format[64 + 1];
    memset(format, 0, 64 + 1);
    switch (hex_prefix) {
    case CFAKER_NUMBER_HEX_HASH:
        strcpy(format, "#");
        break;
    case CFAKER_NUMBER_HEX_ZeroX:
        strcpy(format, "0x");
    default:
        break;
    }

    for (uint32_t i = 0; i < length; i++) {
        strcat(format, "^");
    }

    return cfaker_format_replace_hexchars(format, upper);
}

const char* cfaker_number_hexadecimal_byrange(int32_t min, int32_t max) {
    int32_t number = cfaker_random_int(min, max);
    return cfaker_format_replace_specifier("0x%x", number);
}

const char* cfaker_number_octal_byrange(int32_t min, int32_t max) {
    int32_t number = cfaker_random_int(min, max);
    return cfaker_format_replace_specifier("0o%o", number);
}

const char* cfaker_number_binary_byrange(int32_t min, int32_t max) {
    int32_t number = cfaker_random_int(min, max);
    int64_t binary = 0;
    int32_t remainder, i = 1;

    while (number != 0) {
        remainder = number % 2;
        number /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return cfaker_format_replace_specifier("0b%o", binary);
}
