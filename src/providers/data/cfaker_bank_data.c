#include "providers/data/cfaker_bank_data.h"

static const char* names_en_US[] = {
    "JPMorgan Chase & Co.",
    "Bank of America Corporation",
    "Citigroup Inc.",
    "Wells Fargo & Company",
    "Goldman Sachs Group, Inc.",
    "Morgan Stanley",
    "U.S. Bancorp",
    "PNC Financial Services Group, Inc.",
    "Truist Financial Corporation",
    "Charles Schwab Corporation",
    "TD Bank, N.A.",
    "Capital One Financial Corporation",
    "The Bank of New York Mellon Corporation",
    "BMO Harris Bank N.A.",
    "Teachers Insurance and Annuity Association of America",
    "State Street Corporation",
    "HSBC Bank USA",
    "UBS Group AG",
    "American Express Company",
    "Citizens Financial Group, Inc.",
    "Fifth Third Bank, N.A.",
    "M&T Bank Corporation",
    "Ally Financial Inc.",
    "KeyBank National Association",
    "Huntington National Bank",
    "Barclays Bank Delaware",
    "USAA Federal Savings Bank",
    "State Farm Bank, F.S.B.",
    "MUFG Union Bank, N.A.",
    "Ameriprise Financial, Inc.",
    "Northern Trust Corporation",
    "Regions Financial Corporation",
    "Santander Bank, N.A.",
    "Royal Bank of Canada",
    "Discover Financial Services",
    "Deutsche Bank Trust Company Americas",
    "Synchrony Financial",
    "First Citizens BancShares, Inc.",
    "New York Community Bank",
    "Zions Bancorporation, N.A.",
    "Comerica Incorporated",
    "First Horizon Corporation",
    "Popular, Inc.",
    "Synovus Financial Corp.",
    "Mizuho Bank (USA)",
    "East West Bancorp, Inc.",
    "CIBC Bank USA",
    "TCF Financial Corporation",
    "Raymond James Financial, Inc.",
    "BOK Financial Corporation",
};

const struct cfaker_bank cfaker_bank_en_US = {
    .names = names_en_US,
    .bank_count = sizeof(names_en_US) / sizeof(names_en_US[0]),
};

static const char* names_zh_CN[] = {
    "中国工商银行", "中国建设银行", "中国农业银行", "中国银行",     "中国邮政储蓄银行", "交通银行", "招商银行",
    "浦发银行",     "兴业银行",     "中信银行",     "中国光大银行", "中国民生银行",     "平安银行", "华夏银行",
    "广发银行",     "上海银行",     "北京银行",     "南京银行",     "杭州银行",         "宁波银行", "温州银行",
};

const struct cfaker_bank cfaker_bank_zh_CN = {
    .names = names_zh_CN,
    .bank_count = sizeof(names_zh_CN) / sizeof(names_zh_CN[0]),
};
