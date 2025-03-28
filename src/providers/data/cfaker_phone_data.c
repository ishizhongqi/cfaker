#include "providers/data/cfaker_phone_data.h"

/* Global list of country calling codes for random selection */
/* This could be expanded based on your needs */
const char* global_country_codes[] = {
    "+93",       "+358 18",  "+355",     "+213",       "+1 684",   "+376",   "+244",     "+1 264",   "+1 268",
    "+54",       "+374",     "+297",     "+247",       "+61",      "+672 1", "+672",     "+43",      "+994",
    "+1 242",    "+973",     "+880",     "+1 246",     "+1 268",   "+375",   "+32",      "+501",     "+229",
    "+1 441",    "+975",     "+591",     "+599 7",     "+387",     "+267",   "+55",      "+246",     "+1 284",
    "+673",      "+359",     "+226",     "+257",       "+855",     "+237",   "+1",       "+238",     "+599 3",
    "+599 4",    "+599 7",   "+1 345",   "+236",       "+235",     "+64",    "+56",      "+86",      "+61 89164",
    "+61 89162", "+57",      "+269",     "+242",       "+243",     "+682",   "+506",     "+385",     "+53",
    "+599 9",    "+357",     "+420",     "+45",        "+246",     "+253",   "+1 767",   "+1 809",   "+1 829",
    "+1 849",    "+670",     "+56",      "+593",       "+20",      "+503",   "+881 2",   "+881 3",   "+882 13",
    "+240",      "+291",     "+372",     "+268",       "+251",     "+500",   "+298",     "+679",     "+358",
    "+33",       "+596",     "+594",     "+689",       "+241",     "+220",   "+995",     "+49",      "+233",
    "+350",      "+881",     "+881 8",   "+881 9",     "+30",      "+299",   "+1 473",   "+590",     "+1 671",
    "+502",      "+44 1481", "+44 7781", "+44 7839",   "+44 7911", "+224",   "+245",     "+592",     "+509",
    "+504",      "+852",     "+36",      "+354",       "+881 0",   "+881 1", "+91",      "+62",      "+870",
    "+800",      "+882",     "+883",     "+979",       "+808",     "+98",    "+964",     "+353",     "+881 6",
    "+881 7",    "+44 1624", "+44 7524", "+44 7624",   "+44 7924", "+972",   "+39",      "+225",     "+1 876",
    "+47 79",    "+81",      "+44 1534", "+962",       "+7 6",     "+7 7",   "+254",     "+686",     "+850",
    "+82",       "+383",     "+965",     "+996",       "+856",     "+371",   "+961",     "+266",     "+231",
    "+218",      "+423",     "+370",     "+352",       "+853",     "+261",   "+265",     "+60",      "+960",
    "+223",      "+356",     "+692",     "+596",       "+222",     "+230",   "+262 269", "+262 639", "+52",
    "+691",      "+1 808",   "+373",     "+377",       "+976",     "+382",   "+1 664",   "+212",     "+258",
    "+95",       "+374 47",  "+374 97",  "+264",       "+674",     "+977",   "+31",      "+1 869",   "+687",
    "+64",       "+505",     "+227",     "+234",       "+683",     "+672 3", "+389",     "+90 392",  "+44 28",
    "+1 670",    "+47",      "+968",     "+92",        "+680",     "+970",   "+507",     "+675",     "+595",
    "+51",       "+63",      "+64",      "+48",        "+351",     "+1 787", "+1 939",   "+974",     "+262",
    "+40",       "+7",       "+250",     "+599 4",     "+590",     "+290",   "+1 869",   "+1 758",   "+590",
    "+508",      "+1 784",   "+685",     "+378",       "+239",     "+966",   "+221",     "+381",     "+248",
    "+232",      "+65",      "+599 3",   "+1 721",     "+421",     "+386",   "+677",     "+252",     "+27",
    "+500",      "+995 34",  "+211",     "+34",        "+94",      "+249",   "+597",     "+47 79",   "+46",
    "+41",       "+963",     "+886",     "+992",       "+255",     "+888",   "+66",      "+882 16",  "+228",
    "+690",      "+676",     "+373 2",   "+373 5",     "+1 868",   "+290 8", "+216",     "+90",      "+993",
    "+1 649",    "+688",     "+256",     "+380",       "+971",     "+44",    "+1",       "+878",     "+598",
    "+1 340",    "+998",     "+678",     "+39 06 698", "+379",     "+58",    "+84",      "+1 808",   "+681",
    "+967",      "+260",     "+255 24",  "+263",
};
const size_t global_country_code_count = sizeof(global_country_codes) / sizeof(global_country_codes[0]);

/* en_US phone number formats with $ for area code (2-9 as first digit) */
static const char* formats_en_US[] = {
    "($##) ###-####", /* e.g., (256) 789-1234 */
    "$##-###-####",   /* e.g., 256-789-1234 */
    "$##.###.####",   /* e.g., 256.789.1234 */
};

/* en_US country calling code */
static const char* country_codes_en_US[] = {
    "+1", /* United States */
};

const struct cfaker_phone cfaker_phone_en_US = {
    .mobile_prefixes = NULL,
    .mobile_prefix_count = 0,
    .country_codes = country_codes_en_US,
    .country_code_count = sizeof(country_codes_en_US) / sizeof(country_codes_en_US[0]),
    .formats = formats_en_US,
    .format_count = sizeof(formats_en_US) / sizeof(formats_en_US[0]),
};

/* zh_CN mobile prefixes (common operator prefixes in China) */
static const char* mobile_prefixes_zh_CN[] = {
    "130", "131", "132", "133", "134", "135", "136", "137", "138", "139", "150", "151", "152", "153",
    "155", "156", "157", "158", "159", "166", "167", "170", "171", "173", "175", "176", "177", "178",
    "180", "181", "182", "183", "184", "185", "186", "187", "188", "189", "190", "191", "198", "199",
};

/* zh_CN phone number formats */
static const char* formats_zh_CN[] = {
    "{prefix} #### ####", /* e.g., 138 1234 5678 */
    "{prefix}########",   /* e.g., 13812345678 */
};

/* zh_CN country calling code */
static const char* country_codes_zh_CN[] = {
    "+86", /* China */
};

const struct cfaker_phone cfaker_phone_zh_CN = {
    .mobile_prefixes = mobile_prefixes_zh_CN,
    .mobile_prefix_count = sizeof(mobile_prefixes_zh_CN) / sizeof(mobile_prefixes_zh_CN[0]),
    .country_codes = country_codes_zh_CN,
    .country_code_count = sizeof(country_codes_zh_CN) / sizeof(country_codes_zh_CN[0]),
    .formats = formats_zh_CN,
    .format_count = sizeof(formats_zh_CN) / sizeof(formats_zh_CN[0]),
};
