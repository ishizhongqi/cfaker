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

static struct cfaker_datetime get_cfaker_datetime() {
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

time_t cfaker_datetime_timestamp(const char* start, const char* end) {
    return cfaker_random_timestamp(start, end);
}

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

unsigned int cfaker_datetime_year() {
    return cfaker_random_int(1970, 2030);
}

unsigned int cfaker_datetime_month() {
    return cfaker_random_int(1, 12);
}

unsigned int cfaker_datetime_hour() {
    return cfaker_random_int(0, 23);
}

unsigned int cfaker_datetime_minute() {
    return cfaker_random_int(0, 59);
}

unsigned int cfaker_datetime_second() {
    return cfaker_random_int(0, 59);
}

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

unsigned int cfaker_datetime_day_of_week() {
    return cfaker_random_int(1, 7);
}
