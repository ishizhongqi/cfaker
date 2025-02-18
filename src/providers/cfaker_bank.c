#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_bank.h"
#include "providers/data/cfaker_bank_data.h"

const char* cfaker_bank_name() {
    enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_bank_en_US.banks[cfaker_random_int(0, cfaker_bank_en_US.bank_count - 1)];
        break;
    case zh_CN:
        return cfaker_bank_zh_CN.banks[cfaker_random_int(0, cfaker_bank_zh_CN.bank_count - 1)];
        break;
    default:
        break;
    }
    return cfaker_bank_en_US.banks[cfaker_random_int(0, cfaker_bank_en_US.bank_count - 1)];
}
