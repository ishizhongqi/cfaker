#ifndef __CFAKER_COLOR_DATA_H__
#define __CFAKER_COLOR_DATA_H__

#include <stddef.h>

struct cfaker_color {
    const char** names;
    size_t name_count;
};

extern const struct cfaker_color cfaker_color_en_US;
extern const struct cfaker_color cfaker_color_zh_CN;

#endif
