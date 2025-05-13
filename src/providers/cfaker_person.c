#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_person.h"
#include "providers/data/cfaker_person_data.h"

static struct cfaker_person get_cfaker_person() {
    const enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_person_en_US;
    case zh_CN:
        return cfaker_person_zh_CN;
    default:
        break;
    }
    return cfaker_person_en_US;
}

const char* cfaker_person_first_name(enum cfaker_person_gender gender) {
    const struct cfaker_person person = get_cfaker_person();
    switch (gender) {
    case CFAKER_PERSON_FEMALE:
        return person.first_names_female[cfaker_random_uint(0, person.first_name_female_count - 1)];
    case CFAKER_PERSON_MALE:
        return person.first_names_male[cfaker_random_uint(0, person.first_name_male_count - 1)];
    case CFAKER_PERSON_ANY:
    default:
        break;
    }
    return cfaker_random_int(0, 1) ? person.first_names_female[cfaker_random_uint(0, person.first_name_female_count - 1)]
                                   : person.first_names_male[cfaker_random_uint(0, person.first_name_male_count - 1)];
}

const char* cfaker_person_last_name() {
    const struct cfaker_person person = get_cfaker_person();
    return person.last_names[cfaker_random_uint(0, person.last_name_count - 1)];
}

const char* cfaker_person_prefix(enum cfaker_person_gender gender) {
    const struct cfaker_person person = get_cfaker_person();
    switch (gender) {
    case CFAKER_PERSON_FEMALE:
        return person.prefixes_female[cfaker_random_uint(0, person.prefix_female_count - 1)];
    case CFAKER_PERSON_MALE:
        return person.prefixes_male[cfaker_random_uint(0, person.prefix_male_count - 1)];
    case CFAKER_PERSON_ANY:
    default:
        break;
    }
    return cfaker_random_int(0, 1) ? person.prefixes_female[cfaker_random_uint(0, person.prefix_female_count - 1)]
                                   : person.prefixes_male[cfaker_random_uint(0, person.prefix_male_count - 1)];
}

const char* cfaker_person_suffix(enum cfaker_person_gender gender) {
    const struct cfaker_person person = get_cfaker_person();
    switch (gender) {
    case CFAKER_PERSON_FEMALE:
        return person.suffixes_female[cfaker_random_uint(0, person.suffix_female_count - 1)];
    case CFAKER_PERSON_MALE:
        return person.suffixes_male[cfaker_random_uint(0, person.suffix_male_count - 1)];
    case CFAKER_PERSON_ANY:
    default:
        break;
    }
    return cfaker_random_int(0, 1) ? person.suffixes_female[cfaker_random_uint(0, person.suffix_female_count - 1)]
                                   : person.suffixes_male[cfaker_random_uint(0, person.suffix_male_count - 1)];
}

const char* cfaker_person_full_name(enum cfaker_person_gender gender) {
    const struct cfaker_person person = get_cfaker_person();
    const struct cfaker_format_mapping mappings[] = {
        { "first_name", cfaker_person_first_name(gender) },
        { "last_name", cfaker_person_last_name() },
    };
    return cfaker_format_replace_string(person.formats[cfaker_random_uint(0, person.format_count - 1)], mappings, 2);
}
