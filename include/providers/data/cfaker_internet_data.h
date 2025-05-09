#ifndef __CFAKER_INTERNET_DATA_H__
#define __CFAKER_INTERNET_DATA_H__

#include <stddef.h>

struct cfaker_internet {
    const char** tlds;
    size_t tld_count;
    const char** domain_words;
    size_t domain_word_count;
    const char** domain_formats;
    size_t domain_format_count;
    const char** usernames;
    size_t username_count;
    const char** username_formats;
    size_t username_format_count;
    const char** password_formats;
    size_t password_format_count;
    const char** email_formats;
    size_t email_format_count;
    const char** url_formats;
    size_t url_format_count;
};

extern const struct cfaker_internet cfaker_internet_en_US;
extern const struct cfaker_internet cfaker_internet_zh_CN;

#endif
