#ifndef __CFAKER_PHONE_H__
#define __CFAKER_PHONE_H__

#include <stdbool.h>

/**
 * @brief Generates a country calling code based on the current locale or a random one.
 *
 * @param use_locale If true, returns the code for the current locale; if false, returns a random code.
 * @returns A country calling code string (e.g., "+1" for en_US, "+86" for zh_CN).
 *
 * @code
 * cfaker_phone_code(true);  // Might return "+1" if locale is en_US
 * cfaker_phone_code(false); // Might return any code, e.g., "+44"
 * @endcode
 */
const char* cfaker_phone_code(bool use_locale);

/**
 * @brief Generates a fake phone number based on the current locale.
 *
 * @returns A formatted phone number string (e.g., "(202) 555-0123" for en_US).
 *
 * @code
 * cfaker_phone_number(); // Might return "(202) 555-0123"
 * @endcode
 */
const char* cfaker_phone_number();

#endif /* __CFAKER_PHONE_H__ */
