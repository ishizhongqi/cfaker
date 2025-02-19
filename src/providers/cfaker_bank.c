#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_bank.h"
#include "providers/data/cfaker_bank_data.h"

static const struct cfaker_bank get_cfaker_bank() {
    enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_bank_en_US;
        break;
    case zh_CN:
        return cfaker_bank_zh_CN;
        break;
    default:
        break;
    }
    return cfaker_bank_en_US;
}

const char* cfaker_bank_name() {
    const struct cfaker_bank bank = get_cfaker_bank();
    return bank.banks[cfaker_random_int(0, bank.bank_count - 1)];
}
