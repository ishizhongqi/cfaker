#include "providers/data/cfaker_card_data.h"

static const char* pan_formats_en_US[] = {
    "4###############",
    "51##############",
    "52##############",
    "53##############",
    "54##############",
    "55##############",
    "222%############",
    "223#############",
    "224#############",
    "225#############",
    "226#############",
    "227#############",
    "228#############",
    "229#############",
    "23##############",
    "24##############",
    "25##############",
    "26##############",
    "270#############",
    "271#############",
    "2720############",
    "34#############",
    "37#############",
};

static const char* cvv2_formats_en_US[] = {
    "###",
    "###",
    "####",
};

static const char* issuers_en_US[] = {
    "Visa",
    "Mastercard",
    "American Express",
};

const struct cfaker_card cfaker_card_en_US = {
    .pan_formats = pan_formats_en_US,
    .pan_format_count = sizeof(pan_formats_en_US) / sizeof(pan_formats_en_US[0]),
    .cvv2_formats = cvv2_formats_en_US,
    .cvv2_format_count = sizeof(cvv2_formats_en_US) / sizeof(cvv2_formats_en_US[0]),
    .issuers = issuers_en_US,
    .issuer_count = sizeof(issuers_en_US) / sizeof(issuers_en_US[0]),
};

static const char* pan_formats_zh_CN[] = {
    "622202#############", /* 工商银行（ICBC）借记卡 */
    "622230#############", /* 工商银行（ICBC）借记卡 */
    "621661#############", /* 工商银行（ICBC）借记卡 */
    "621700#############", /* 建设银行（CCB）借记卡 */
    "622280#############", /* 建设银行（CCB）借记卡 */
    "622848#############", /* 农业银行（ABC）借记卡 */
    "621282#############", /* 农业银行（ABC）借记卡 */
    "621661#############", /* 中国银行（BOC）借记卡 */
    "621660#############", /* 中国银行（BOC）借记卡 */
    "621663#############", /* 中国银行（BOC）借记卡 */
    "621483##########",    /* 招商银行（CMB）借记卡 */

    "622230##########", /* 工商银行（ICBC）信用卡 */
    "622246##########", /* 工商银行（ICBC）信用卡 */
    "625956##########", /* 建设银行（CCB）信用卡 */
    "625955##########", /* 建设银行（CCB）信用卡 */
    "622848##########", /* 农业银行（ABC）信用卡 */
    "621282##########", /* 农业银行（ABC）信用卡 */
    "621660##########", /* 中国银行（BOC）信用卡 */
    "621661##########", /* 中国银行（BOC）信用卡 */
    "622576##########", /* 招商银行（CMB）信用卡 */
};

static const char* cvv2_formats_zh_CN[] = {
    "###",
};

static const char* issuers_zh_CN[] = {
    "银联",
};

const struct cfaker_card cfaker_card_zh_CN = {
    .pan_formats = pan_formats_zh_CN,
    .pan_format_count = sizeof(pan_formats_zh_CN) / sizeof(pan_formats_zh_CN[0]),
    .cvv2_formats = cvv2_formats_zh_CN,
    .cvv2_format_count = sizeof(cvv2_formats_zh_CN) / sizeof(cvv2_formats_zh_CN[0]),
    .issuers = issuers_zh_CN,
    .issuer_count = sizeof(issuers_zh_CN) / sizeof(issuers_zh_CN[0]),
};
