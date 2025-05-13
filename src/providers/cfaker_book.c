#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_book.h"
#include "providers/data/cfaker_book_data.h"

static struct cfaker_book get_cfaker_book() {
    const enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_book_en_US;
    case zh_CN:
        return cfaker_book_zh_CN;
    default:
        break;
    }
    return cfaker_book_en_US;
}

const char* cfaker_book_title() {
    const struct cfaker_book book = get_cfaker_book();
    return book.titles[cfaker_random_uint(0, book.title_count - 1)];
}

const char* cfaker_book_author() {
    const struct cfaker_book book = get_cfaker_book();
    return book.authors[cfaker_random_uint(0, book.author_count - 1)];
}

const char* cfaker_book_genre() {
    const struct cfaker_book book = get_cfaker_book();
    return book.genres[cfaker_random_uint(0, book.genre_count - 1)];
}

const char* cfaker_book_publisher() {
    const struct cfaker_book book = get_cfaker_book();
    return book.publishers[cfaker_random_uint(0, book.publisher_count - 1)];
}

const char* cfaker_book_format() {
    const struct cfaker_book book = get_cfaker_book();
    return book.formats[cfaker_random_uint(0, book.format_count - 1)];
}

const char* cfaker_book_series() {
    const struct cfaker_book book = get_cfaker_book();
    return book.series[cfaker_random_uint(0, book.series_count - 1)];
}
