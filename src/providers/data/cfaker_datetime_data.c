#include "providers/data/cfaker_datetime_data.h"

static const char* abbreviated_month[] = {
    "Apr", "Aug", "Dec", "Feb", "Jan", "July", "June", "Mar", "May", "Nov", "Oct", "Sept",
};

static const char* abbreviated_weekday[] = {
    "Fri", "Mon", "Sat", "Sun", "Thu", "Tue", "Wed",
};

static const char* abbreviated_timezones[] = {
    "ACDT",  "ACST", "ACT",          "ACT",  "ACWST", "ADT",   "AEDT",  "AEST",  "AET (AEST/AEDT)",
    "AFT",   "AKDT", "AKST",         "ALMT", "AMST",  "AMT",   "AMT",   "ANAT",  "AQTT",
    "ART",   "AST",  "AST",          "AWST", "AZOST", "AZOT",  "AZT",   "BIOT",  "BIT",
    "BNT",   "BOT",  "BRST",         "BRT",  "BST",   "BST",   "BST",   "BTT",   "CAT",
    "CCT",   "CDT",  "CDT",          "CEST", "CET",   "CHADT", "CHAST", "CHOST", "CHOT",
    "CHST",  "CHUT", "CIST",         "CKT",  "CLST",  "CLT",   "COST",  "COT",   "CST",
    "CST",   "CST",  "CT (CST/CDT)", "CVT",  "CWST",  "CXT",   "DAVT",  "DDUT",  "DFT",
    "EASST", "EAST", "EAT",          "ECT",  "ECT",   "EDT",   "EEST",  "EET",   "EGST",
    "EGT",   "EST",  "ET (EST/EDT)", "FET",  "FJT",   "FKST",  "FKT",   "FNT",   "GALT",
    "GAMT",  "GET",  "GFT",          "GILT", "GIT",   "GMT",   "GST",   "GST",   "GYT",
    "HAEC",  "HDT",  "HKT",          "HMT",  "HOVST", "HOVT",  "HST",   "ICT",   "IDLW",
    "IDT",   "IOT",  "IRDT",         "IRKT", "IRST",  "IST",   "IST",   "IST",   "JST",
    "KALT",  "KGT",  "KOST",         "KRAT", "KST",   "LHST",  "LHST",  "LINT",  "MAGT",
    "MART",  "MAWT", "MDT",          "MEST", "MET",   "MHT",   "MIST",  "MIT",   "MMT",
    "MSK",   "MST",  "MST",          "MUT",  "MVT",   "MYT",   "NCT",   "NDT",   "NFT",
    "NOVT",  "NPT",  "NST",          "NT",   "NUT",   "NZDT",  "NZST",  "OMST",  "ORAT",
    "PDT",   "PET",  "PETT",         "PGT",  "PHOT",  "PHST",  "PHT",   "PKT",   "PMDT",
    "PMST",  "PONT", "PST",          "PWT",  "PYST",  "PYT",   "RET",   "ROTT",  "SAKT",
    "SAMT",  "SAST", "SBT",          "SCT",  "SDT",   "SGT",   "SLST",  "SRET",  "SRT",
    "SST",   "SST",  "SYOT",         "TAHT", "TFT",   "THA",   "TJT",   "TKT",   "TLT",
    "TMT",   "TOT",  "TRT",          "TST",  "TVT",   "ULAST", "ULAT",  "UTC",   "UYST",
    "UYT",   "UZT",  "VET",          "VLAT", "VOLT",  "VOST",  "VUT",   "WAKT",  "WAST",
    "WAT",   "WEST", "WET",          "WGST", "WGT",   "WIB",   "WIT",   "WITA",  "WST",
    "YAKT",  "YEKT",
};

static const char* month_en_US[] = {
    "April", "August", "December", "February", "January", "July",
    "June",  "March",  "May",      "November", "October", "September",
};

static const char* weekday_en_US[] = {
    "Friday", "Monday", "Saturday", "Sunday", "Thursday", "Tuesday", "Wednesday",
};

const struct cfaker_datetime cfaker_datetime_en_US = {
    .month = month_en_US,
    .month_count = sizeof(month_en_US) / sizeof(month_en_US[0]),
    .abbreviated_month = abbreviated_month,
    .abbreviated_month_count = sizeof(abbreviated_month) / sizeof(abbreviated_month[0]),
    .weekday = weekday_en_US,
    .weekday_count = sizeof(weekday_en_US) / sizeof(weekday_en_US[0]),
    .abbreviated_weekday = abbreviated_weekday,
    .abbreviated_weekday_count = sizeof(abbreviated_weekday) / sizeof(abbreviated_weekday[0]),
    .abbreviated_timezones = abbreviated_timezones,
    .abbreviated_timezone_count = sizeof(abbreviated_timezones) / sizeof(abbreviated_timezones[0]),
};

static const char* month_zh_CN[] = {
    "一月", "二月", "三月", "四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月",
};

static const char* weekday_zh_CN[] = {
    "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六",
};

const struct cfaker_datetime cfaker_datetime_zh_CN = {
    .month = month_zh_CN,
    .month_count = sizeof(month_zh_CN) / sizeof(month_zh_CN[0]),
    .abbreviated_month = abbreviated_month,
    .abbreviated_month_count = sizeof(abbreviated_month) / sizeof(abbreviated_month[0]),
    .weekday = weekday_zh_CN,
    .weekday_count = sizeof(weekday_zh_CN) / sizeof(weekday_zh_CN[0]),
    .abbreviated_weekday = abbreviated_weekday,
    .abbreviated_weekday_count = sizeof(abbreviated_weekday) / sizeof(abbreviated_weekday[0]),
    .abbreviated_timezones = abbreviated_timezones,
    .abbreviated_timezone_count = sizeof(abbreviated_timezones) / sizeof(abbreviated_timezones[0]),
};
