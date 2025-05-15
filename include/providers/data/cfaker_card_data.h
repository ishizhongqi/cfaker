#ifndef __CFAKER_CARD_DATA_H__
#define __CFAKER_CARD_DATA_H__

#include <stddef.h>

struct cfaker_card {
    const char** pan_formats;
    size_t pan_format_count;
    const char** cvv2_formats;
    size_t cvv2_format_count;
    const char** issuers;
    size_t issuer_count;
};

extern const struct cfaker_card cfaker_card_en_US;
extern const struct cfaker_card cfaker_card_zh_CN;

#endif /* __CFAKER_CARD_DATA_H__ */
