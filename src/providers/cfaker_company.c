#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_company.h"
#include "providers/data/cfaker_company_data.h"

#include "providers/cfaker_person.h"

static struct cfaker_company get_cfaker_company() {
    const enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_company_en_US;
    case zh_CN:
        return cfaker_company_zh_CN;
    default:
        break;
    }
    return cfaker_company_en_US;
}

const char* cfaker_company_prefix() {
    const struct cfaker_company company = get_cfaker_company();
    if (company.prefix_count == 0) {
        return NULL;
    }
    return company.prefixes[cfaker_random_uint(0, company.prefix_count - 1)];
}

const char* cfaker_company_suffix() {
    const struct cfaker_company company = get_cfaker_company();
    return company.suffixes[cfaker_random_uint(0, company.suffix_count - 1)];
}

const char* cfaker_company_name() {
    const struct cfaker_company company = get_cfaker_company();
    const struct cfaker_format_mapping mappings[] = {
        { "last_name", cfaker_person_last_name() },  { "last_name1", cfaker_person_last_name() },
        { "last_name2", cfaker_person_last_name() }, { "prefix", cfaker_company_prefix() },
        { "suffix", cfaker_company_suffix() },
    };
    return cfaker_format_replace_string(company.formats[cfaker_random_uint(0, company.format_count - 1)], mappings, 3);
}
