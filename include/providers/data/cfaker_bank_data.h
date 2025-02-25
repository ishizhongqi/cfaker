#ifndef __CFAKER_BANK_DATA_H__
#define __CFAKER_BANK_DATA_H__

#include <stddef.h>

struct cfaker_bank {
    const char** names; /* List of banks */
    size_t bank_count;  /* Number of banks */
};

extern const struct cfaker_bank cfaker_bank_en_US;
extern const struct cfaker_bank cfaker_bank_zh_CN;

#endif
