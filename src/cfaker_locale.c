#include "cfaker_locale.h"

#include <string.h>

static enum cfaker_locale current_locale = en_US;

static const char* locale_strings[] = {
    "af_ZA",  /* Afrikaans", South Africa */
    "am_ET",  /* Amharic", Ethiopia */
    "ar_AE",  /* Arabic", United Arab Emirates */
    "ar_BH",  /* Arabic", Bahrain */
    "ar_DZ",  /* Arabic", Algeria */
    "ar_EG",  /* Arabic", Egypt */
    "ar_IQ",  /* Arabic", Iraq */
    "ar_JO",  /* Arabic", Jordan */
    "ar_KW",  /* Arabic", Kuwait */
    "ar_LB",  /* Arabic", Lebanon */
    "ar_LY",  /* Arabic", Libya */
    "ar_MA",  /* Arabic", Morocco */
    "ar_OM",  /* Arabic", Oman */
    "ar_PS",  /* Arabic", Palestinian Territory */
    "ar_QA",  /* Arabic", Qatar */
    "ar_SA",  /* Arabic", Saudi Arabia */
    "ar_SD",  /* Arabic", Sudan */
    "ar_SY",  /* Arabic", Syria */
    "ar_TN",  /* Arabic", Tunisia */
    "ar_YE",  /* Arabic", Yemen */
    "arn_CL", /* Mapudungun", Chile */
    "as_IN",  /* Assamese", India */
    "az_AZ",  /* Azerbaijani", Azerbaijan */
    "ba_RU",  /* Bashkir", Russia */
    "be_BY",  /* Belarusian", Belarus */
    "bg_BG",  /* Bulgarian", Bulgaria */
    "bn_BD",  /* Bengali", Bangladesh */
    "bn_IN",  /* Bengali", India */
    "bo_CN",  /* Tibetan", China */
    "br_FR",  /* Breton", France */
    "bs_BA",  /* Bosnian", Bosnia and Herzegovina */
    "ca_ES",  /* Catalan", Spain */
    "co_FR",  /* Corsican", France */
    "cs_CZ",  /* Czech", Czech Republic */
    "cy_GB",  /* Welsh", United Kingdom */
    "da_DK",  /* Danish", Denmark */
    "de_AT",  /* German", Austria */
    "de_BE",  /* German", Belgium */
    "de_CH",  /* German", Switzerland */
    "de_DE",  /* German", Germany */
    "de_LI",  /* German", Liechtenstein */
    "de_LU",  /* German", Luxembourg */
    "dsb_DE", /* Lower Sorbian", Germany */
    "dv_MV",  /* Divehi", Maldives */
    "el_CY",  /* Greek", Cyprus */
    "el_GR",  /* Greek", Greece */
    "en_029", /* English", Caribbean */
    "en_AU",  /* English", Australia */
    "en_BW",  /* English", Botswana */
    "en_BZ",  /* English", Belize */
    "en_CA",  /* English", Canada */
    "en_cb",  /* English", Caribbean */
    "en_GB",  /* English", United Kingdom */
    "en_GH",  /* English", Ghana */
    "en_HK",  /* English", Hong Kong SAR China */
    "en_IE",  /* English", Ireland */
    "en_IN",  /* English", India */
    "en_JM",  /* English", Jamaica */
    "en_MT",  /* English", Malta */
    "en_MY",  /* English", Malaysia */
    "en_NZ",  /* English", New Zealand */
    "en_PH",  /* English", Philippines */
    "en_SG",  /* English", Singapore */
    "en_TT",  /* English", Trinidad and Tobago */
    "en_US",  /* English", U.S.A. */
    "en_ZA",  /* English", South Africa */
    "en_ZW",  /* English", Zimbabwe */
    "es_AR",  /* Spanish", Argentina */
    "es_BO",  /* Spanish", Bolivia */
    "es_CL",  /* Spanish", Chile */
    "es_CO",  /* Spanish", Colombia */
    "es_CR",  /* Spanish", Costa Rica */
    "es_DO",  /* Spanish", Dominican Republic */
    "es_EC",  /* Spanish", Ecuador */
    "es_ES",  /* Spanish", Spain */
    "es_GT",  /* Spanish", Guatemala */
    "es_HN",  /* Spanish", Honduras */
    "es_MX",  /* Spanish", Mexico */
    "es_NI",  /* Spanish", Nicaragua */
    "es_PA",  /* Spanish", Panama */
    "es_PE",  /* Spanish", Peru */
    "es_PR",  /* Spanish", Puerto Rico */
    "es_PY",  /* Spanish", Paraguay */
    "es_SV",  /* Spanish", El Salvador */
    "es_US",  /* Spanish", U.S.A. */
    "es_UY",  /* Spanish", Uruguay */
    "es_VE",  /* Spanish", Venezuela */
    "et_EE",  /* Estonian", Estonia */
    "eu_ES",  /* Basque", Spain */
    "fa_IR",  /* Persian", Iran */
    "fi_FI",  /* Finnish", Finland */
    "fil_PH", /* Filipino", Philippines */
    "fo_FO",  /* Faroese", Faroe Islands */
    "fr_BE",  /* French", Belgium */
    "fr_CA",  /* French", Canada */
    "fr_CH",  /* French", Switzerland */
    "fr_FR",  /* French", France */
    "fr_LU",  /* French", Luxembourg */
    "fr_MC",  /* French", Monaco */
    "fy_NL",  /* Western Frisian", Netherlands */
    "ga_IE",  /* Irish", Ireland */
    "gd_GB",  /* Scottish Gaelic", United Kingdom */
    "gd_ie",  /* Gaelic", Ireland */
    "gl_ES",  /* Galician", Spain */
    "gsw_FR", /* Swiss German", France */
    "gu_IN",  /* Gujarati", India */
    "he_IL",  /* Hebrew", Israel */
    "hi_IN",  /* Hindi", India */
    "hr_BA",  /* Croatian", Bosnia and Herzegovina */
    "hr_HR",  /* Croatian", Croatia */
    "hsb_DE", /* Upper Sorbian", Germany */
    "hu_HU",  /* Hungarian", Hungary */
    "hy_AM",  /* Armenian", Armenia */
    "id_ID",  /* Indonesian", Indonesia */
    "ig_NG",  /* Igbo", Nigeria */
    "ii_CN",  /* Sichuan Yi", China */
    "in_ID",  /* Indonesian", Indonesia */
    "is_IS",  /* Icelandic", Iceland */
    "it_CH",  /* Italian", Switzerland */
    "it_IT",  /* Italian", Italy */
    "iw_IL",  /* Hebrew", Israel */
    "ja_JP",  /* Japanese", Japan */
    "ka_GE",  /* Georgian", Georgia */
    "kk_KZ",  /* Kazakh", Kazakhstan */
    "kl_GL",  /* Kalaallisut", Greenland */
    "km_KH",  /* Khmer", Cambodia */
    "kn_IN",  /* Kannada", India */
    "ko_KR",  /* Korean", Korea */
    "kok_IN", /* Konkani", India */
    "ks_IN",  /* Kashmiri", India */
    "ku_TR",  /* Kurdish", Turkey */
    "ky_KG",  /* Kirghiz", Kyrgyzstan */
    "lb_LU",  /* Luxembourgish", Luxembourg */
    "lo_LA",  /* Lao", Laos */
    "lt_LT",  /* Lithuanian", Lithuania */
    "lv_LV",  /* Latvian", Latvia */
    "mi_NZ",  /* Maori", New Zealand */
    "mk_MK",  /* Macedonian", Macedonia */
    "ml_IN",  /* Malayalam", India */
    "mn_MN",  /* Mongolian", Mongolia */
    "moh_CA", /* Mohawk", Canada */
    "mr_IN",  /* Marathi", India */
    "ms_BN",  /* Malay", Brunei */
    "ms_MY",  /* Malay", Malaysia */
    "mt_MT",  /* Maltese", Malta */
    "nb_NO",  /* Norwegian Bokmal", Norway */
    "ne_NP",  /* Nepali", Nepal */
    "nl_BE",  /* Dutch", Belgium */
    "nl_NL",  /* Dutch", Netherlands */
    "nn_NO",  /* Norwegian Nynorsk", Norway */
    "no_no",  /* Norwegian", Norway */
    "nso_ZA", /* Northern Sotho", South Africa */
    "oc_FR",  /* Occitan", France */
    "or_IN",  /* Oriya", India */
    "pa_IN",  /* Punjabi", India */
    "pl_PL",  /* Polish", Poland */
    "prs_AF", /* Dari", Afghanistan */
    "ps_AF",  /* Pashto", Afghanistan */
    "pt_BR",  /* Portuguese", Brazil */
    "pt_PT",  /* Portuguese", Portugal */
    "qut_GT", /* K'iche", Guatemala */
    "quz_BO", /* Quechua", Bolivia */
    "quz_EC", /* Quechua", Ecuador */
    "quz_PE", /* Quechua", Peru */
    "rm_CH",  /* Romansh", Switzerland */
    "ro_MD",  /* Romanian", Moldova */
    "ro_RO",  /* Romanian", Romania */
    "ru_RU",  /* Russian", Russia */
    "ru_UA",  /* Russian", Ukraine */
    "rw_RW",  /* Kinyarwanda", Rwanda */
    "sa_IN",  /* Sanskrit", India */
    "sah_RU", /* Sakha", Russia */
    "se_FI",  /* Northern Sami", Finland */
    "se_NO",  /* Northern Sami", Norway */
    "se_SE",  /* Northern Sami", Sweden */
    "si_LK",  /* Sinhala", Sri Lanka */
    "sk_SK",  /* Slovak", Slovakia */
    "sl_SI",  /* Slovenian", Slovenia */
    "sma_NO", /* Southern Sami", Norway */
    "sma_SE", /* Southern Sami", Sweden */
    "smj_NO", /* Lule Sami", Norway */
    "smj_SE", /* Lule Sami", Sweden */
    "smn_FI", /* Inari Sami", Finland */
    "sms_FI", /* Skolt Sami", Finland */
    "sq_AL",  /* Albanian", Albania */
    "sr_BA",  /* Serbian", Bosnia and Herzegovina */
    "sr_CS",  /* Serbian", Serbia and Montenegro */
    "sr_ME",  /* Serbian", Montenegro */
    "sr_RS",  /* Serbian", Serbia */
    "sv_FI",  /* Swedish", Finland */
    "sv_SE",  /* Swedish", Sweden */
    "sw_KE",  /* Swahili", Kenya */
    "syr_SY", /* Syriac", Syria */
    "ta_IN",  /* Tamil", India */
    "te_IN",  /* Telugu", India */
    "th_TH",  /* Thai", Thailand */
    "tk_TM",  /* Turkmen", Turkmenistan */
    "tn_ZA",  /* Tswana", South Africa */
    "tr_TR",  /* Turkish", Turkey */
    "tt_RU",  /* Tatar", Russian */
    "ug_CN",  /* Uyghur", China */
    "uk_UA",  /* Ukrainian", Ukraine */
    "ur_PK",  /* Urdu", Pakistan */
    "uz_uz",  /* Uzbek", Uzbekistan */
    "vi_VN",  /* Vietnamese", Vietnam */
    "wo_SN",  /* Wolof", Senegal */
    "xh_ZA",  /* Xhosa", South Africa */
    "yo_NG",  /* Yoruba", Nigeria */
    "zh_CN",  /* Simplified Chinese", China */
    "zh_HK",  /* Traditional Chinese", Hong Kong SAR China */
    "zh_MO",  /* Traditional Chinese", Macao SAR China */
    "zh_SG",  /* Simplified Chinese", Singapore */
    "zh_TW",  /* Traditional Chinese", Taiwan */
    "zu_ZA",  /* Zulu", South Africa */
};

void cfaker_locale_set(enum cfaker_locale locale) {
    current_locale = locale;
}

void cfaker_locale_set_bystring(const char* locale) {
    for (int i = 0; i < cfaker_locale_count; i++) {
        if (strcmp(locale, locale_strings[i]) == 0) {
            current_locale = i;
            return;
        }
    }
}

enum cfaker_locale cfaker_locale_get() {
    return current_locale;
}
