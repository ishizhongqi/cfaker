#ifndef __CFAKER_PERSON_DATA_H__
#define __CFAKER_PERSON_DATA_H__

#include <stddef.h>

struct cfaker_person {
    const char** first_names_female; /* List of first names */
    size_t first_name_female_count;  /* Number of first names */

    const char** first_names_male; /* List of first names */
    size_t first_name_male_count;  /* Number of first names */

    const char** last_names; /* List of last names */
    size_t last_name_count;  /* Number of last names */

    const char** prefixes_female; /* Female prefixes (e.g., Mrs.) */
    size_t prefix_female_count;

    const char** prefixes_male; /* Male prefixes (e.g., Mr.) */
    size_t prefix_male_count;

    const char** suffixes_female; /* Suffixes (e.g., MD) */
    size_t suffix_female_count;

    const char** suffixes_male; /* Suffixes (e.g., Jr., III) */
    size_t suffix_male_count;

    const char* format_full_name; /* Example: "{first_name} {last_name}" */
};

/* Global variables for locale-specific data */
extern const struct cfaker_person cfaker_person_en_US;
extern const struct cfaker_person cfaker_person_zh_CN;

#endif /* __CFAKER_PERSON_DATA_H__ */
