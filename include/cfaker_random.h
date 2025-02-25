#ifndef __CFAKER_RANDOM_H__
#define __CFAKER_RANDOM_H__

#include <stddef.h>
#include <stdint.h>
#include <time.h>

/**
 * @brief Initialize the random number and character generator.
 * This function is called in cfaker_init() and does not need to be called again if cfaker_init() is called.
 *
 * @param size The size of the buffer.
 *
 * @returns 0 on success, 1 on failure.
 *
 * @code
 * cfaker_random_init(1024); // Initializes with buffer size 1024
 * @endcode
 */
int cfaker_random_init(size_t size);

/**
 * @brief Generate a random 32-bit integer.
 *
 * @param min The minimum value.
 * @param max The maximum value.
 *
 * @returns A random 32-bit integer between `min` and `max`.
 *
 * @code
 * cfaker_random_int(10, 100); // 42
 * @endcode
 */
int32_t cfaker_random_int(int32_t min, int32_t max);

/**
 * @brief Returns a random double value within the given range.
 *
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (inclusive).
 * @returns A random double value between min and max.
 *
 * @code
 * cfaker_random_double(1.5, 5.5); // e.g., 3.2764
 * @endcode
 */
double cfaker_random_double(double min, double max);

/**
 * @brief Generate a random digit (0 to 9).
 *
 * @returns A random digit between 0 and 9.
 *
 * @code
 * cfaker_random_digit(); // 5
 * @endcode
 */
uint32_t cfaker_random_digit();

/**
 * @brief Generate a random non-zero digit (1 to 9).
 *
 * @returns A random non-zero digit between 1 and 9.
 *
 * @code
 * cfaker_random_digit_non_zero(); // 7
 * @endcode
 */
uint32_t cfaker_random_digit_non_zero();

/**
 * @brief Generate a random digit above value two (2 to 9).
 *
 * @returns A random digit between 2 and 9.
 *
 * @code
 * cfaker_random_digit_above_two(); // 4
 * @endcode
 */
uint32_t cfaker_random_digit_above_two();

/**
 * @brief Generate a random digit character ('0' to '9') or an empty character.
 * This method will return an empty character 50% of the time,
 * and each digit has a 1/20 chance of being generated.
 *
 * @returns A random digit character ('0' to '9') or an empty character.
 *
 * @code
 * cfaker_random_digit_or_empty(); // '5'
 * @endcode
 */
char cfaker_random_digit_or_empty();

/**
 * @brief Generate a random non-zero digit character ('1' to '9') or an empty character.
 * This method will return an empty character 50% of the time,
 * and each digit has a 1/18 chance of being generated.
 *
 * @returns A random non-zero digit character ('1' to '9') or an empty character.
 *
 * @code
 * cfaker_random_digit_non_zero_or_empty(); // '9'
 * @endcode
 */
char cfaker_random_digit_non_zero_or_empty();

/**
 * @brief Generate a random hexadecimal character ('0' to '9', 'a' to 'f').
 *
 * @returns A random hexadecimal character.
 *
 * @code
 * cfaker_random_hexchar(); // 'b'
 * @endcode
 */
char cfaker_random_hexchar();

/**
 * @brief Generate a random lowercase ASCII letter (a-z).
 *
 * @returns A random lowercase ASCII letter.
 *
 * @code
 * cfaker_random_lowercase_letter(); // 'g'
 * @endcode
 */
char cfaker_random_lowercase_letter();

/**
 * @brief Generate a random uppercase ASCII letter (A-Z).
 *
 * @returns A random uppercase ASCII letter.
 *
 * @code
 * cfaker_random_uppercase_letter(); // 'T'
 * @endcode
 */
char cfaker_random_uppercase_letter();

/**
 * @brief Generate a random ASCII letter (a-z, A-Z).
 *
 * @returns A random ASCII letter.
 *
 * @code
 * cfaker_random_letter(); // 'B'
 * @endcode
 */
char cfaker_random_letter();

/**
 * @brief Generate a list of random ASCII letters (a-z and A-Z).
 *
 * @param size The length of the letters to generate.
 *
 * @returns A pointer to a string containing randomly generated letters.
 *
 * @code
 * cfaker_random_letters(5); // "tQwOp"
 * @endcode
 */
char* cfaker_random_letters(uint32_t size);

/**
 * @brief Generate a list of randomly sampled objects from ``elements``.
 *
 * @param elements The list of elements.
 * @param count The number of elements.
 * @param length The number of elements to sample. If 0, a random number of elements will be sampled.
 * @param unique If non-zero, the sample will be unique.
 *
 * @returns A list of randomly sampled elements.
 *
 * @code
 * cfaker_random_elements(elements, 5, 3, 1); // Sampled unique elements
 * @endcode
 */
const char** cfaker_random_elements(const char** elements, size_t count, size_t length, int unique);

/**
 * @brief Generate a list of objects randomly sampled from ``elements`` with replacement.
 * Calls ``cfaker_random_elements()`` with unique = 0.
 *
 * @param elements The list of elements.
 * @param count The number of elements.
 * @param length The number of elements to sample. If 0, a random number of elements will be sampled.
 *
 * @returns A list of randomly sampled elements.
 *
 * @code
 * cfaker_random_choices(elements, 5, 3); // Sampled elements with replacement
 * @endcode
 */
const char** cfaker_random_choices(const char** elements, size_t count, size_t length);

/**
 * @brief Generate a randomly sampled object from ``elements``.
 * Calls ``cfaker_random_elements()`` with length = 1.
 *
 * @param elements The list of elements.
 * @param count The number of elements.
 *
 * @returns A random element from the list.
 *
 * @code
 * cfaker_random_element(elements, 5); // Sampled single element
 * @endcode
 */
const char* cfaker_random_element(const char** elements, size_t count);

/**
 * @brief Generate a list of randomly sampled objects from ``elements`` without replacement.
 * Calls ``cfaker_random_elements()`` with unique = 1.
 *
 * @param elements The list of elements.
 * @param count The number of elements.
 * @param length The number of elements to sample. If 0, a random number of elements will be sampled.
 *
 * @returns A list of randomly sampled elements.
 *
 * @code
 * cfaker_random_sample(elements, 5, 3); // Sampled elements without replacement
 * @endcode
 */
const char** cfaker_random_sample(const char** elements, size_t count, size_t length);

/**
 * @brief Generate a random number of elements based on a given number.
 * The result is a random number that is roughly within a certain range.
 *
 * @param number The base number.
 * @param le If non-zero, the upper bound is limited to 100% (otherwise it can rise to 140%).
 * @param ge If non-zero, the lower bound is limited to 100% (otherwise it can drop to 60%).
 * @param min_val If you do not want the result to be less than a certain value (if there is no such restriction, you
 * can pass -1).
 * @param max_val If you do not want the result to be higher than a certain value (if there is no such restriction, you
 * can pass -1).
 *
 * @returns A random number of elements based on the given number.
 *
 * @code
 * cfaker_random_randomize(10, 1, 0, -1, -1); // Randomized number of elements
 * @endcode
 */
int cfaker_random_randomize(int number, int le, int ge, int min_val, int max_val);

/**
 * @brief Generate a random timestamp between two given start and end times.
 *
 * @param start A string representing the start date-time in the format "YYYY-MM-DD HH:MM:SS".
 * @param end A string representing the end date-time in the format "YYYY-MM-DD HH:MM:SS".
 *
 * @returns A random timestamp (time_t) between the given start and end times.
 *
 * @code
 * cfaker_random_timestamp("2020-01-01 00:00:00", "2025-12-31 23:59:59"); // Random timestamp
 * @endcode
 */
time_t cfaker_random_timestamp(const char* start, const char* end);

/**
 * @brief Free the memory allocated by the random number and character generator.
 *
 * @code
 * cfaker_random_free(); // Frees allocated memory
 * @endcode
 */
void cfaker_random_free();

#endif
