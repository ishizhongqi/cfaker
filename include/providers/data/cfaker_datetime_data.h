#ifndef __CFAKER_DATETIME_DATA_H__
#define __CFAKER_DATETIME_DATA_H__

#include <stddef.h>

struct cfaker_datetime {
    const char** month;
    size_t month_count;
    const char** abbreviated_month;
    size_t abbreviated_month_count;
    const char** weekday;
    size_t weekday_count;
    const char** abbreviated_weekday;
    size_t abbreviated_weekday_count;
    const char** abbreviated_timezones;
    size_t abbreviated_timezone_count;
};

extern const struct cfaker_datetime cfaker_datetime_en_US;
extern const struct cfaker_datetime cfaker_datetime_zh_CN;

#endif
