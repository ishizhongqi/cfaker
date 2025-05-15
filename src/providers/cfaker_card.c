#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_card.h"
#include "providers/data/cfaker_card_data.h"

static struct cfaker_card get_cfaker_card() {
    const enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_card_en_US;
    case zh_CN:
        return cfaker_card_zh_CN;
    default:
        break;
    }
    return cfaker_card_en_US;
}


const char* cfaker_card_pan() {
    const struct cfaker_card card = get_cfaker_card();
    return cfaker_format_replace_numbers(card.pan_formats[cfaker_random_uint(0, card.pan_format_count - 1)]);
}

const char* cfaker_card_cvv2() {
    const struct cfaker_card card = get_cfaker_card();
    return cfaker_format_replace_numbers(card.cvv2_formats[cfaker_random_uint(0, card.cvv2_format_count - 1)]);
}

const char* cfaker_card_issuer() {
    const struct cfaker_card card = get_cfaker_card();
    return card.issuers[cfaker_random_uint(0, card.issuer_count - 1)];
}
