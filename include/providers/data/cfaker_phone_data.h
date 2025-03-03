#ifndef __CFAKER_PHONE_DATA_H__
#define __CFAKER_PHONE_DATA_H__

#include <stddef.h>

extern const char* global_country_codes[];
extern const size_t global_country_code_count;

struct cfaker_phone {
    const char** mobile_prefixes; /**< Array of mobile number prefixes (e.g., "130" for zh_CN) */
    size_t mobile_prefix_count;   /**< Number of mobile prefixes in the array */
    const char** country_codes;   /**< Array of country calling codes (e.g., "+1" for en_US) */
    size_t country_code_count;    /**< Number of country codes in the array */
    const char** formats;         /**< Array of phone number formats specific to the locale */
    size_t format_count;          /**< Number of formats in the array */
};

extern const struct cfaker_phone cfaker_phone_en_US;
extern const struct cfaker_phone cfaker_phone_zh_CN;

#endif /* __CFAKER_PHONE_DATA_H__ */
