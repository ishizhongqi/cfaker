#ifndef __CFAKER_DATETIME_H__
#define __CFAKER_DATETIME_H__

#include <time.h>

/**
 * @brief Enumeration for datetime formatting options.
 */
enum cfaker_datetime_form {
    CFAKER_DATETIME_ABBREVIATED, /**< Abbreviated format (e.g., "Mon", "Jan"). */
    CFAKER_DATETIME_FULL,        /**< Full format (e.g., "Monday", "January"). */
};

/**
 * @brief Returns a random timestamp within the given date range.
 *
 * @param start The start date in the format "YYYY-MM-DD".
 * @param end The end date in the format "YYYY-MM-DD".
 *
 * @returns A time_t value representing a timestamp within the range.
 *
 * @code
 * cfaker_datetime_timestamp("2000-01-01", "2020-12-31"); // 1577836800
 * @endcode
 */
time_t cfaker_datetime_timestamp(const char* start, const char* end);

/**
 * @brief Returns a formatted datetime string within the given date range.
 *
 * @param format The format string (e.g., "%Y-%m-%d %H:%M:%S").
 * @param start The start date in the format "YYYY-MM-DD".
 * @param end The end date in the format "YYYY-MM-DD".
 *
 * @returns A pointer to a constant string representing the formatted datetime.
 *
 * @code
 * cfaker_datetime_datetime("%Y-%m-%d", "2000-01-01", "2020-12-31"); // "2015-06-18"
 * @endcode
 */
const char* cfaker_datetime_datetime(const char* format, const char* start, const char* end);

/**
 * @brief Returns a random month name.
 *
 * @param form The format of the month name (abbreviated or full).
 *
 * @returns A pointer to a constant string representing the month name.
 *
 * @code
 * cfaker_datetime_month_name(CFAKER_DATETIME_FULL); // "January"
 * cfaker_datetime_month_name(CFAKER_DATETIME_ABBREVIATED); // "Jan"
 * @endcode
 */
const char* cfaker_datetime_month_name(enum cfaker_datetime_form form);

/**
 * @brief Returns a random weekday name.
 *
 * @param form The format of the weekday name (abbreviated or full).
 *
 * @returns A pointer to a constant string representing the weekday name.
 *
 * @code
 * cfaker_datetime_weekday_name(CFAKER_DATETIME_FULL); // "Monday"
 * cfaker_datetime_weekday_name(CFAKER_DATETIME_ABBREVIATED); // "Mon"
 * @endcode
 */
const char* cfaker_datetime_weekday_name(enum cfaker_datetime_form form);

/**
 * @brief Returns a random timezone name.
 *
 * @returns A pointer to a constant string representing the timezone.
 *
 * @code
 * cfaker_datetime_timezone(); // "UTC"
 * @endcode
 */
const char* cfaker_datetime_timezone();

/**
 * @brief Returns a random year.
 *
 * @returns A randomly generated year.
 *
 * @code
 * cfaker_datetime_year(); // 2023
 * @endcode
 */
unsigned int cfaker_datetime_year();

/**
 * @brief Returns a random month (1-12).
 *
 * @returns A randomly generated month.
 *
 * @code
 * cfaker_datetime_month(); // 7
 * @endcode
 */
unsigned int cfaker_datetime_month();

/**
 * @brief Returns a random hour (0-23).
 *
 * @returns A randomly generated hour.
 *
 * @code
 * cfaker_datetime_hour(); // 15
 * @endcode
 */
unsigned int cfaker_datetime_hour();

/**
 * @brief Returns a random minute (0-59).
 *
 * @returns A randomly generated minute.
 *
 * @code
 * cfaker_datetime_minute(); // 42
 * @endcode
 */
unsigned int cfaker_datetime_minute();

/**
 * @brief Returns a random second (0-59).
 *
 * @returns A randomly generated second.
 *
 * @code
 * cfaker_datetime_second(); // 18
 * @endcode
 */
unsigned int cfaker_datetime_second();

/**
 * @brief Returns a random day of the month for the given month.
 *
 * @param month The month (1-12).
 *
 * @returns A randomly generated day of the month.
 *
 * @code
 * cfaker_datetime_day_of_month(2); // 14
 * @endcode
 */
unsigned int cfaker_datetime_day_of_month(unsigned int month);

/**
 * @brief Returns a random day of the week (0-6, where 0 = Sunday).
 *
 * @returns A randomly generated day of the week.
 *
 * @code
 * cfaker_datetime_day_of_week(); // 3 (Wednesday)
 * @endcode
 */
unsigned int cfaker_datetime_day_of_week();

#endif
