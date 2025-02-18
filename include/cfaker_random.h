#ifndef __CFAKER_RANDOM_H__
#define __CFAKER_RANDOM_H__

#include <stddef.h>
#include <stdint.h>

/**
 * Initialize the random number and character generator.
 * This function is called in cfaker_init() and does not need to be called again if cfaker_init() is called.
 * @param size The size of the buffer.
 * @return 0 on success, 1 on failure.
 *
 */
int cfaker_random_init(size_t size);

/**
 * Generate a random 32-bit integer.
 * @param min The minimum value.
 * @param max The maximum value.
 * @return A random 32-bit integer.
 */
uint32_t cfaker_random_int(uint32_t min, uint32_t max);

/**
 * Generate a random digit (0 to 9).
 */
uint32_t cfaker_random_digit();

/**
 * Generate a random non-zero digit (1 to 9).
 */
uint32_t cfaker_random_digit_non_zero();

/**
 * Generate a random digit above value two (2 to 9).
 */
uint32_t cfaker_random_digit_above_two();

/**
 * Generate a random digit character ('0' to '9') or an empty character.
 * This method will return an empty character 50% of the time,
 * and each digit has a 1/20 chance of being generated.
 */
char cfaker_random_digit_or_empty();

/**
 * Generate a random non-zero digit character ('1' to '9') or an empty character.
 * This method will return an empty character 50% of the time,
 * and each digit has a 1/18 chance of being generated.
 */
char cfaker_random_digit_non_zero_or_empty();

/**
 * Generate a random hexadecimal character ('0' to '9', 'a' to 'f').
 */
char cfaker_random_hexchar();

/**
 * Generate a random lowercase ASCII letter (a-z).
 */
char cfaker_random_lowercase_letter();

/**
 * Generate a random uppercase ASCII letter (A-Z).
 */
char cfaker_random_uppercase_letter();

/**
 * Generate a random ASCII letter (a-z, A-Z).
 */
char cfaker_random_letter();

/**
 * Generate a list of random ASCII letters (a-z and A-Z).
 * @param size The length of letters.
 *
 */
char* cfaker_random_letters(uint32_t size);

/**
 * Generate a list of randomly sampled objects from ``elements``.
 * @param elements The list of elements.
 * @param count The number of elements.
 * @param length The number of elements to sample. If 0, a random number of elements will be sampled.
 * @param unique If non-zero, the sample will be unique.
 * @return A list of randomly sampled elements.
 */
const char** cfaker_random_elements(const char** elements, size_t count, size_t length, int unique);

/**
 * Generate a list of objects randomly sampled from ``elements`` with replacement.
 * Calls ``cfaker_random_elements()`` with unique = 0.
 * @param elements The list of elements.
 * @param count The number of elements.
 * @param length The number of elements to sample. If 0, a random number of elements will be sampled.
 * @return A list of randomly sampled elements.
 */
const char** cfaker_random_choices(const char** elements, size_t count, size_t length);

/**
 * Generate a randomly sampled object from ``elements``.
 * Calls ``cfaker_random_elements()`` with length = 1.
 * @param elements The list of elements.
 * @param count The number of elements.
 * @return A random element.
 */
const char* cfaker_random_element(const char** elements, size_t count);

/**
 * Generate a list of randomly sampled objects from ``elements`` without replacement.
 * Calls ``cfaker_random_elements()`` with unique = 1.
 * @param elements The list of elements.
 * @param count The number of elements.
 * @param length The number of elements to sample. If 0, a random number of elements will be sampled.
 * @return A list of randomly sampled elements.
 */
const char** cfaker_random_sample(const char** elements, size_t count, size_t length);

/**
 * Generate a random number of elements based on a given number.
 * The result is a random number that is roughly within a certain range.
 * @param number The base number.
 * @param le If non-zero, the upper bound is limited to 100% (otherwise it can rise to 140%).
 * @param ge If non-zero, the lower bound is limited to 100% (otherwise it can drop to 60%).
 * @param min_val If you do not want the result to be less than a certain value (if there is no such restriction, you
 * can pass -1).
 * @param max_val If you do not want the result to be higher than a certain value (if there is no such restriction, you
 * can pass -1).
 * @return A random number of elements.
 */
int cfaker_random_randomize(int number, int le, int ge, int min_val, int max_val);

/**
 * Free the memory allocated by the random number and character generator.
 */
void cfaker_random_free();

#endif
