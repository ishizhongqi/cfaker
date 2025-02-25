#ifndef CFAKER_FORMAT_H
#define CFAKER_FORMAT_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Structure for mapping tokens to their string values.
 *
 * @note This structure is used to associate a token (e.g., "firstname") with its corresponding value (e.g., "John").
 */
struct cfaker_format_mapping {
    const char* token; /**< Token name, e.g., "firstname" */
    const char* value; /**< Corresponding replacement string */
};

/**
 * @brief Initialize the format generator.
 * This function is called in cfaker_init() and does not need to be called again if cfaker_init() is called.
 *
 * @param size The size of the buffer.
 *
 * @returns 0 on success, 1 on failure.
 *
 * @code
 * cfaker_format_init(1024); // Initializes format generator with buffer size 1024
 * @endcode
 */
int cfaker_format_init(size_t size);

const char* cfaker_format_replace_specifier(const char* format, ...);

/**
 * @brief Replace tokens in a format string with their corresponding values.
 *
 * @param format The format string.
 * @param mappings An array of mappings from tokens to values.
 * @param mapping_count The number of mappings.
 *
 * @returns The formatted string with tokens replaced by their corresponding values.
 *
 * @code
 * cfaker_format_replace_string("{firstname} {lastname}", mappings, 2); // "John Doe"
 * @endcode
 */
const char* cfaker_format_replace_string(const char* format, const struct cfaker_format_mapping* mappings,
                                         size_t mapping_count);

/**
 * @brief Generate a string with each placeholder in ``text`` replaced according to specific rules:
 * - Number signs ('#') are replaced with a random digit (0 to 9).
 * - Percent signs ('%') are replaced with a random non-zero digit (1 to 9).
 * - Dollar signs ('$') are replaced with a random digit above two (2 to 9).
 * - Exclamation marks ('!') are replaced with a random digit or an empty string.
 * - At symbols ('@') are replaced with a random non-zero digit or an empty string.
 *
 * @param format The format string.
 *
 * @returns A formatted string with placeholders replaced.
 *
 * @code
 * cfaker_format_replace_numbers("Phone: ###-###-####"); // "Phone: 123-456-7890"
 * @endcode
 */
const char* cfaker_format_replace_numbers(const char* format);

/**
 * @brief Generate a string with each question mark ('?') in ``text`` replaced with a random character from ``letters``.
 * By default, ``letters`` contains all ASCII letters, uppercase and lowercase.
 *
 * @param format The format string.
 * @param letters The list of characters to choose from. If NULL, all ASCII letters are used.
 *
 * @returns A formatted string with '?' replaced by random letters.
 *
 * @code
 * cfaker_format_replace_letters("Hello ???"); // "Hello abc"
 * @endcode
 */
const char* cfaker_format_replace_letters(const char* format, const char* letters);

/**
 * @brief Generate a string in accordance with the rules of `cfaker_format_replace_numbers` and
 * `cfaker_format_replace_letters`.
 *
 * @param format The format string.
 * @param hexchars The list of characters to choose from. If NULL, all ASCII letters or numbers are used.
 *
 * @returns A formatted string with '#' and '?' replaced by random characters.
 *
 * @code
 * cfaker_format_replace_chars("Color code: #??"); // "Color code: 3af"
 * @endcode
 */
const char* cfaker_format_replace_chars(const char* format, const char* letters);

/**
 * @brief Generate a string with each circumflex ('^') in ``text`` replaced with a random hexadecimal character.
 * By default, ``upper`` is set to 0. If set to 1, output will be formatted using uppercase hexadecimal characters.
 *
 * @param format The format string.
 * @param upper If non-zero, output will be formatted using uppercase hexadecimal characters.
 *
 * @returns A formatted string with '^' replaced by random hexadecimal characters.
 *
 * @code
 * cfaker_format_replace_hexchars("Hex code: ^^^"); // "Hex code: 3fA"
 * @endcode
 */
const char* cfaker_format_replace_hexchars(const char* format, bool upper);

/**
 * @brief Formats a datetime string based on a format string and a random timestamp generated between two provided
 * dates.
 *
 * @param format A format string containing datetime format specifiers (e.g., "%Y-%m-%d %H:%M:%S").
 * @param start A string representing the start date-time in the format "YYYY-MM-DD HH:MM:SS".
 * @param end A string representing the end date-time in the format "YYYY-MM-DD HH:MM:SS".
 *
 * @returns A formatted datetime string based on the random timestamp generated within the specified range.
 *
 * @code
 * cfaker_format_replace_datetime("%Y-%m-%d %H:%M:%S", "2020-01-01 00:00:00", "2025-12-31 23:59:59");
 * // "2023-06-12 14:45:38"
 * @endcode
 */
const char* cfaker_format_replace_datetime(const char* format, const char* start, const char* end);

/**
 * @brief Free the memory allocated by the format generator.
 *
 * @code
 * cfaker_format_free(); // Frees allocated memory for the format generator
 * @endcode
 */
void cfaker_format_free();

#endif /* CFAKER_FORMAT_H */
