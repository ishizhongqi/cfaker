#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_internet.h"
#include "providers/data/cfaker_internet_data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct cfaker_internet get_cfaker_internet() {
    enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_internet_en_US;
        break;
    case zh_CN:
        return cfaker_internet_zh_CN;
        break;
    default:
        break;
    }
    return cfaker_internet_en_US;
}

const char* cfaker_internet_tlds() {
    const struct cfaker_internet internet = get_cfaker_internet();
    return cfaker_random_element(internet.tlds, internet.tld_count);
}

const char* cfaker_internet_domain(uint32_t levels) {
    const struct cfaker_internet internet = get_cfaker_internet();

    if (levels < 1) {
        return NULL;
    }

    // if (levels == 1) {
    //     struct cfaker_format_mapping mappings[] = {
    //         { "domain_word", internet.domain_words[cfaker_random_int(0, internet.domain_word_count - 1)] },
    //         { "domain_name", cfaker_internet_tlds() },
    //     };
    //     return cfaker_format_replace_string(
    //         internet.domain_formats[cfaker_random_int(0, internet.domain_format_count - 1)], mappings, 2);
    // } else {
    //     struct cfaker_format_mapping mappings[] = {
    //         { "domain_word", internet.domain_words[cfaker_random_int(0, internet.domain_word_count - 1)] },
    //         { "domain_name", cfaker_internet_domain(levels - 1) },
    //     };
    //     return cfaker_format_replace_string(
    //         internet.domain_formats[cfaker_random_int(0, internet.domain_format_count - 1)], mappings, 2);
    // }

    return NULL;
}

const char* cfaker_internet_username() {
    const struct cfaker_internet internet = get_cfaker_internet();
    struct cfaker_format_mapping mappings[] = {
        { "username", cfaker_random_element(internet.usernames, internet.username_count) },
    };
    return cfaker_format_replace_string(
        internet.username_formats[cfaker_random_int(0, internet.username_format_count - 1)], mappings, 1);
}

const char* cfaker_internet_password(uint32_t length, uint8_t char_flags) {
    const struct cfaker_internet internet = get_cfaker_internet();

    typedef struct {
        const char* chars;
        size_t len;
    } CharSet;

    size_t total_chars = 0;
    CharSet sets[7];
    size_t num_sets = 0;

    if (char_flags & CFAKER_INTERNET_LOWERLETTER) {
        sets[num_sets++] = (CharSet){ "abcdefghijklmnopqrstuvwxyz", 26 };
        total_chars += 26;
    }
    if (char_flags & CFAKER_INTERNET_UPPERLETTER) {
        sets[num_sets++] = (CharSet){ "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26 };
        total_chars += 26;
    }
    if (char_flags & CFAKER_INTERNET_NUMBER) {
        sets[num_sets++] = (CharSet){ "0123456789", 10 };
        total_chars += 10;
    }
    if (char_flags & CFAKER_INTERNET_PERIOD) {
        sets[num_sets++] = (CharSet){ ".", 1 };
        total_chars += 1;
    }
    if (char_flags & CFAKER_INTERNET_UNDERSCORE) {
        sets[num_sets++] = (CharSet){ "_", 1 };
        total_chars += 1;
    }
    if (char_flags & CFAKER_INTERNET_HYPHEN) {
        sets[num_sets++] = (CharSet){ "-", 1 };
        total_chars += 1;
    }
    if (char_flags & CFAKER_INTERNET_SPECIAL) {
        sets[num_sets++] = (CharSet){ "!@#$%^&*", 8 };
        total_chars += 8;
    }

    // 有效性检查
    if (num_sets == 0 || length == 0 || length < num_sets) {
        return NULL;
    }

    // 构建候选池
    char* candidate_chars = malloc(total_chars);
    if (!candidate_chars)
        return NULL;

    size_t pos = 0;
    for (size_t i = 0; i < num_sets; i++) {
        memcpy(candidate_chars + pos, sets[i].chars, sets[i].len);
        pos += sets[i].len;
    }

    // 生成密码
    char* password = cfaker_format_replace_string(
        internet.password_formats[cfaker_random_int(0, internet.password_format_count - 1)], NULL, 0);

    // 确保每个字符集至少一个字符
    for (size_t i = 0; i < num_sets; i++) {
        password[i] = sets[i].chars[cfaker_random_int(0, sets[i].len - 1)];
    }

    // 填充剩余字符
    for (size_t i = num_sets; i < length; i++) {
        password[i] = candidate_chars[cfaker_random_int(0, total_chars - 1)];
    }

    // 打乱顺序（Fisher-Yates洗牌算法）
    for (size_t i = length - 1; i > 0; i--) {
        size_t j = cfaker_random_int(0, i);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0';
    free(candidate_chars);
    candidate_chars = NULL;
    return password;
}

const char* cfaker_internet_email(const char* domain) {}

const char* cfaker_internet_url(const char* schemes) {}

const char* cfaker_internet_ipv4() {}

const char* cfaker_internet_ipv6() {}

const char* cfaker_internet_mac() {}

const char* cfaker_internet_port() {}
