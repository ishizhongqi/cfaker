#ifndef __CFAKER_DATETIME_DATA_H__
#define __CFAKER_DATETIME_DATA_H__

#include <stddef.h>

struct cfaker_datetime {
    const char** month; /* List of month */
    size_t month_count; /* Number of month */

    const char** abbreviated_month; /* List of abbreviated_month */
    size_t abbreviated_month_count; /* Number of abbreviated_month */

    const char** weekday; /* List of weekday */
    size_t weekday_count; /* Number of weekday */

    const char** abbreviated_weekday; /* List of abbreviated_weekday */
    size_t abbreviated_weekday_count; /* Number of abbreviated_weekday */

    const char** abbreviated_timezones; /* List of abbreviated_timezones */
    size_t abbreviated_timezone_count;  /* Number of abbreviated_timezones */
};

extern const struct cfaker_datetime cfaker_datetime_en_US;
extern const struct cfaker_datetime cfaker_datetime_zh_CN;

#endif
