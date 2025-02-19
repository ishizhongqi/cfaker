#ifndef __CFAKER_BOOK_DATA_H__
#define __CFAKER_BOOK_DATA_H__

#include <stddef.h>

struct cfaker_book {
    const char** titles; /* List of book titles */
    size_t title_count;  /* Number of book titles */

    const char** authors; /* List of authors */
    size_t author_count;  /* Number of authors */

    const char** genres; /* List of genres */
    size_t genre_count;  /* Number of genres */

    const char** publishers; /* List of publishers */
    size_t publisher_count;  /* Number of publishers */

    const char** formats; /* List of formats */
    size_t format_count;  /* Number of formats */

    const char** series; /* List of series */
    size_t series_count; /* Number of series */
};

extern const struct cfaker_book cfaker_book_en_US;
extern const struct cfaker_book cfaker_book_zh_CN;

#endif
