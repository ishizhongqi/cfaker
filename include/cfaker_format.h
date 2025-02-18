#ifndef CFAKER_FORMAT_H
#define CFAKER_FORMAT_H

#include <stddef.h>

/* Structure for mapping tokens to their string values */
struct cfaker_format_mapping {
    const char* token; /* Token name, e.g., "firstname" */
    const char* value; /* Corresponding replacement string */
};

/**
 * Initialize the format generator.
 * This function is called in cfaker_init() and does not need to be called again if cfaker_init() is called.
 * @param size The size of the buffer.
 * @return 0 on success, 1 on failure.
 *
 */
int cfaker_format_init(size_t size);

/**
 * Replace tokens in a format string with their corresponding values.
 * @param format The format string.
 * @param mappings An array of mappings from tokens to values.
 * @param mapping_count The number of mappings.
 * @return The formatted string.
 */
const char* cfaker_format_replace_string(const char* format, const struct cfaker_format_mapping* mappings,
                                         size_t mapping_count);

/**
 * Generate a string with each placeholder in ``text`` replaced according to the following rules:
 * - Number signs ('#') are replaced with a random digit (0 to 9).
 * - Percent signs ('%') are replaced with a random non-zero digit (1 to 9).
 * - Dollar signs ('$') are replaced with a random digit above two (2 to 9).
 * - Exclamation marks ('!') are replaced with a random digit or an empty string.
 * - At symbols ('@') are replaced with a random non-zero digit or an empty string.
 * @param format The format string.
 */
const char* cfaker_format_replace_numbers(const char* format);

/**
 * Generate a string with each question mark ('?') in ``text`` replaced with a random character from ``letters``.
 * By default, ``letters`` contains all ASCII letters, uppercase and lowercase.
 * @param format The format string.
 * @param letters The list of characters to choose from. IF NULL, all ASCII letters are used.
 */
const char* cfaker_format_replace_letters(const char* format, const char* letters);

/**
 * Generate a string with each tilde ('~') in ``text`` replaced with a random character from ``hexchars``.
 * By default, ``hexchars`` contains all hexadecimal characters (0-9, a-f).
 * @param format The format string.
 * @param hexchars The list of hexadecimal characters to choose from. IF NULL, all ASCII letters are used.
 */
const char* cfaker_format_replace_chars(const char* format, const char* letters);

/**
 * Generate a string with each circumflex ('^') in ``text`` replaced with a random hexadecimal character.
 * By default, ``upper`` is set to 0. If set to 1, output will be formatted using uppercase hexadecimal
 * characters.
 * @param format The format string.
 * @param upper If non-zero, output will be formatted using uppercase hexadecimal characters.
 */
const char* cfaker_format_replace_hexchars(const char* format, int upper);

void cfaker_format_free();

#endif /* CFAKER_FORMAT_H */
