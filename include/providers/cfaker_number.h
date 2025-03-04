#ifndef __CFAKER_NUMBER_H__
#define __CFAKER_NUMBER_H__

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Enum representing different hex prefix formats.
 */
enum cfaker_number_hex_prefix {
    CFAKER_NUMBER_HEX_HASH,  /**< Hex format with '#' prefix (e.g., "#FF5733"). */
    CFAKER_NUMBER_HEX_NONE,  /**< Hex format without any prefix (e.g., "FF5733"). */
    CFAKER_NUMBER_HEX_ZeroX, /**< Hex format with "0x" prefix (e.g., "0xFF5733"). */
};

/**
 * @brief Returns a random integer within a specified range.
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @returns A random integer between min and max.
 *
 * @code
 * cfaker_number_int(1, 100); // 42
 * @endcode
 */
int32_t cfaker_number_int(int32_t min, int32_t max);

/**
 * @brief Returns a random double within a specified range.
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @returns A random double between min and max.
 *
 * @code
 * cfaker_number_double(0.5, 2.5); // 1.73
 * @endcode
 */
double cfaker_number_double(double min, double max);

/**
 * @brief Returns a random hexadecimal number of a specified length.
 *
 * @param length The number of hexadecimal digits.
 * @param upper If true, returns uppercase hex letters.
 * @param hex_prefix Specifies the prefix format (e.g., none, "0x", or "#").
 * @returns A pointer to a constant string representing the hexadecimal number.
 *
 * @code
 * cfaker_number_hexadecimal_bylength(4, true, CFAKER_NUMBER_HEX_HASH); // "#ABCD"
 * @endcode
 */
const char* cfaker_number_hexadecimal_bylength(uint32_t length, bool upper, enum cfaker_number_hex_prefix hex_prefix);

/**
 * @brief Returns a random hexadecimal number within a specified range.
 *
 * @param min The minimum integer value.
 * @param max The maximum integer value.
 * @returns A pointer to a constant string representing the hexadecimal number.
 *
 * @code
 * cfaker_number_hexadecimal_byrange(100, 500); // "0x1F4"
 * @endcode
 */
const char* cfaker_number_hexadecimal_byrange(int32_t min, int32_t max);

/**
 * @brief Returns a random octal number within a specified range.
 *
 * @param min The minimum integer value.
 * @param max The maximum integer value.
 * @returns A pointer to a constant string representing the octal number.
 *
 * @code
 * cfaker_number_octal_byrange(10, 50); // "0o62"
 * @endcode
 */
const char* cfaker_number_octal_byrange(int32_t min, int32_t max);

/**
 * @brief Returns a random binary number within a specified range.
 *
 * @param min The minimum integer value.
 * @param max The maximum integer value.
 * @returns A pointer to a constant string representing the binary number.
 *
 * @code
 * cfaker_number_binary_byrange(5, 20); // "0b1010"
 * @endcode
 */
const char* cfaker_number_binary_byrange(int32_t min, int32_t max);

#endif
