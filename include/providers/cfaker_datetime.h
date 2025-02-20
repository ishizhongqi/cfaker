#ifndef __CFAKER_DATETIME_H__
#define __CFAKER_DATETIME_H__

#include <time.h>

enum cfaker_datetime_form {
    CFAKER_DATETIME_ABBREVIATED,
    CFAKER_DATETIME_FULL,
};

time_t cfaker_datetime_timestamp(const char* start, const char* end);
const char* cfaker_datetime_datetime(const char* format, const char* start, const char* end);
const char* cfaker_datetime_month_name(enum cfaker_datetime_form form);
const char* cfaker_datetime_weekday_name(enum cfaker_datetime_form form);
const char* cfaker_datetime_timezone();
unsigned int cfaker_datetime_year();
unsigned int cfaker_datetime_month();
unsigned int cfaker_datetime_hour();
unsigned int cfaker_datetime_minute();
unsigned int cfaker_datetime_second();
unsigned int cfaker_datetime_day_of_month(unsigned int month);
unsigned int cfaker_datetime_day_of_week();

#endif
