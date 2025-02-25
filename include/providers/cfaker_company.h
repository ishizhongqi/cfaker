#ifndef __CFAKER_COMPANY_H__
#define __CFAKER_COMPANY_H__

/**
 * @brief Returns a random company prefix.
 *
 * @returns A pointer to a constant string representing the company prefix.
 *
 * @code
 * cfaker_company_prefix(); // "超艺"
 * @endcode
 */
const char* cfaker_company_prefix();

/**
 * @brief Returns a random company suffix.
 *
 * @returns A pointer to a constant string representing the company suffix.
 *
 * @code
 * cfaker_company_suffix(); // "Inc."
 * @endcode
 */
const char* cfaker_company_suffix();

/**
 * @brief Returns a random company name.
 *
 * @returns A pointer to a constant string representing the company name.
 *
 * @code
 * cfaker_company_name(); // "Johnson Inc."
 * @endcode
 */
const char* cfaker_company_name();

#endif
