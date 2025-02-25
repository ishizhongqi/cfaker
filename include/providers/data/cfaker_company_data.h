#ifndef __CFAKER_COMPANY_DATA_H__
#define __CFAKER_COMPANY_DATA_H__

#include <stddef.h>

struct cfaker_company {
    const char** prefixes;
    size_t prefix_count;
    const char** suffixes;
    size_t suffix_count;
    const char** formats;
    size_t format_count;
};

extern const struct cfaker_company cfaker_company_en_US;
extern const struct cfaker_company cfaker_company_zh_CN;

#endif
