#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_phone.h"
#include "providers/data/cfaker_phone_data.h"

#include <stdio.h>

static struct cfaker_phone get_cfaker_phone() {
    enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_phone_en_US;
        break;
    case zh_CN:
        return cfaker_phone_zh_CN;
        break;
    default:
        break;
    }
    return cfaker_phone_en_US; /* Default to en_US */
}

const char* cfaker_phone_code(bool use_locale) {
    if (use_locale) {
        const struct cfaker_phone phone = get_cfaker_phone();
        if (phone.country_code_count > 0) {
            return phone.country_codes[cfaker_random_int(0, phone.country_code_count - 1)];
        }
        return "+1"; /* Fallback */
    }
    return global_country_codes[cfaker_random_int(0, global_country_code_count - 1)];
}

const char* cfaker_phone_number() {
    const struct cfaker_phone phone = get_cfaker_phone();
    const char* format = phone.formats[cfaker_random_int(0, phone.format_count - 1)];
    const char* number;

    /* Handle mobile prefixes (e.g., zh_CN) */
    if (phone.mobile_prefix_count > 0) {
        const char* prefix = phone.mobile_prefixes[cfaker_random_int(0, phone.mobile_prefix_count - 1)];
        struct cfaker_format_mapping mappings[] = {
            { "prefix", prefix },
        };
        number = cfaker_format_replace_string(format, mappings, 1);
    } else {
        number = format; /* For en_US, no prefix */
    }

    /* Generate the number with random digits */
    return cfaker_format_replace_numbers(number);
}
