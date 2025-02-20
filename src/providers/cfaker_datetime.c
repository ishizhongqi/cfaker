#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_datetime.h"
#include "providers/data/cfaker_datetime_data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static const struct cfaker_datetime get_cfaker_datetime() {
    enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_datetime_en_US;
        break;
    case zh_CN:
        return cfaker_datetime_zh_CN;
        break;
    default:
        break;
    }
    return cfaker_datetime_en_US;
}

/* cfaker_datetime_timestamp
   Generates a random timestamp (as a number in string form)
   The 'format' parameter is a printf-style format (e.g. \"%ld\") */
time_t cfaker_datetime_timestamp(const char* start, const char* end) {
    return cfaker_random_timestamp(start, end);
}

/* cfaker_datetime_datetime
   Generates a formatted datetime string using strftime.
   'format' should be a valid strftime format (e.g. \"%Y-%m-%d %H:%M:%S\") */
const char* cfaker_datetime_datetime(const char* format, const char* start, const char* end) {
    return cfaker_format_replace_datetime(format, start, end);
}

const char* cfaker_datetime_month_name(enum cfaker_datetime_form form) {
    const struct cfaker_datetime datetime = get_cfaker_datetime();
    switch (form) {
    case CFAKER_DATETIME_ABBREVIATED:
        return datetime.abbreviated_month[cfaker_random_int(0, datetime.abbreviated_month_count - 1)];
        break;
    case CFAKER_DATETIME_FULL:
    default:
        break;
    }
    return datetime.month[cfaker_random_int(0, datetime.month_count - 1)];
}

const char* cfaker_datetime_weekday_name(enum cfaker_datetime_form form) {
    const struct cfaker_datetime datetime = get_cfaker_datetime();
    switch (form) {
    case CFAKER_DATETIME_ABBREVIATED:
        return datetime.abbreviated_weekday[cfaker_random_int(0, datetime.abbreviated_weekday_count - 1)];
        break;
    case CFAKER_DATETIME_FULL:
    default:
        break;
    }
    return datetime.weekday[cfaker_random_int(0, datetime.weekday_count - 1)];
}

const char* cfaker_datetime_timezone() {
    const struct cfaker_datetime datetime = get_cfaker_datetime();
    return datetime.abbreviated_timezones[cfaker_random_int(0, datetime.abbreviated_timezone_count - 1)];
}

/* cfaker_datetime_year
   Returns a random year within a reasonable range (e.g. 1970-2030) */
unsigned int cfaker_datetime_year() {
    return cfaker_random_int(1970, 2030);
}

/* cfaker_datetime_month
   Returns a random month (1-12) */
unsigned int cfaker_datetime_month() {
    return cfaker_random_int(1, 12);
}

/* cfaker_datetime_hour
   Returns a random hour (0-23) */
unsigned int cfaker_datetime_hour() {
    return cfaker_random_int(0, 23);
}

/* cfaker_datetime_minute
   Returns a random minute (0-59) */
unsigned int cfaker_datetime_minute() {
    return cfaker_random_int(0, 59);
}

/* cfaker_datetime_second
   Returns a random second (0-59) */
unsigned int cfaker_datetime_second() {
    return cfaker_random_int(0, 59);
}

/* cfaker_datetime_day_of_month
   Given a month (1-12), returns a random day of month (1 to max days in that month)
   For simplicity, leap years are not considered. */
unsigned int cfaker_datetime_day_of_month(unsigned int month) {
    unsigned int max_day;
    switch (month) {
    case 2:
        max_day = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        max_day = 30;
        break;
    default:
        max_day = 31;
        break;
    }
    return cfaker_random_int(1, max_day);
}

/* cfaker_datetime_day_of_week
   Returns a random day of the week (1 = Sunday, 7 = Saturday) */
unsigned int cfaker_datetime_day_of_week() {
    return cfaker_random_int(1, 7);
}
