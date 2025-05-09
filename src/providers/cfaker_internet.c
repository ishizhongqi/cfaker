#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_internet.h"
#include "providers/data/cfaker_internet_data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cfaker_internet get_cfaker_internet() {
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
    if (levels < 1)
        return NULL;

    const char* fmt = internet.domain_formats[cfaker_random_int(0, internet.domain_format_count - 1)];

    struct cfaker_format_mapping mappings[2];
    mappings[0].token = "domain_word";
    mappings[0].value = internet.domain_words[cfaker_random_int(0, internet.domain_word_count - 1)];

    if (levels == 1) {
        mappings[1].token = "domain_name";
        mappings[1].value = cfaker_internet_tlds();
        return cfaker_format_replace_string(fmt, mappings, 2);
    } else {
        const char* sub = cfaker_internet_domain(levels - 1);
        char* sub_copy = strdup(sub);
        mappings[1].token = "domain_name";
        mappings[1].value = sub_copy;
        const char* result = cfaker_format_replace_string(fmt, mappings, 2);
        free(sub_copy);
        return result;
    }
}

const char* cfaker_internet_username() {
    const struct cfaker_internet internet = get_cfaker_internet();
    struct cfaker_format_mapping mappings[] = {
        { "username", cfaker_random_element(internet.usernames, internet.username_count) },
    };
    return cfaker_format_replace_chars(
        cfaker_format_replace_string(
            internet.username_formats[cfaker_random_uint(0, internet.username_format_count - 1)], mappings, 1),
        NULL);
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

    if (num_sets == 0 || length == 0 || length < num_sets) {
        return NULL;
    }

    // build the candidate character set
    char* candidate_chars = malloc(total_chars);
    if (!candidate_chars)
        return NULL;

    size_t pos = 0;
    for (size_t i = 0; i < num_sets; i++) {
        memcpy(candidate_chars + pos, sets[i].chars, sets[i].len);
        pos += sets[i].len;
    }

    // generate the password
    char* password = (char*)cfaker_format_replace_string(
        internet.password_formats[cfaker_random_uint(0, internet.password_format_count - 1)], NULL, 0);

    // heck if we have at least one character set
    for (size_t i = 0; i < num_sets; i++) {
        password[i] = sets[i].chars[cfaker_random_uint(0, sets[i].len - 1)];
    }

    // fill the rest of the password with random characters
    for (size_t i = num_sets; i < length; i++) {
        password[i] = candidate_chars[cfaker_random_uint(0, total_chars - 1)];
    }

    // Fisher-Yates
    for (size_t i = length - 1; i > 0; i--) {
        size_t j = cfaker_random_uint(0, i);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0';
    free(candidate_chars);
    candidate_chars = NULL;
    return password;
}

const char* cfaker_internet_email(const char* domain) {
    const struct cfaker_internet internet = get_cfaker_internet();

    /* generate random username */
    const char* username = cfaker_random_element(cfaker_internet_en_US.usernames, cfaker_internet_en_US.username_count);

    /* copy domain_name */
    const char* raw_domain = domain ? domain : cfaker_internet_domain(1);
    char* domain_copy = strdup(raw_domain);
    if (!domain_copy) {
        return NULL;
    }

    struct cfaker_format_mapping mappings[] = { { "username", username }, { "domain_name", domain_copy } };

    const char* result = cfaker_format_replace_string(
        internet.email_formats[cfaker_random_uint(0, internet.email_format_count - 1)], mappings, 2);

    free(domain_copy);

    return result;
}

const char* cfaker_internet_url(const char* schemes) {
    const struct cfaker_internet internet = get_cfaker_internet();

    /* Split schemes on comma */
    char schemes_copy[64];
    memset(schemes_copy, 0, sizeof(schemes_copy));
    strncpy(schemes_copy, schemes ? schemes : "http,https", sizeof(schemes_copy) - 1);
    schemes_copy[sizeof(schemes_copy) - 1] = '\0';
    char* token = strtok(schemes_copy, ",");
    /* Count tokens */
    const char* arr[10];
    int count = 0;
    while (token && count < 10) {
        arr[count++] = token;
        token = strtok(NULL, ",");
    }
    /* Choose one scheme */
    const char* scheme = arr[cfaker_random_uint(0, count - 1)];

    const char* raw_domain = cfaker_internet_domain(2);
    char* domain_copy = strdup(raw_domain);
    if (!domain_copy) {
        return NULL;
    }

    struct cfaker_format_mapping mappings[] = {
        { "scheme", scheme },
        { "domain_name", domain_copy },
    };

    const char* result = cfaker_format_replace_string(
        internet.url_formats[cfaker_random_uint(0, internet.url_format_count - 1)], mappings, 2);

    free(domain_copy);
    return result;
}

const char* cfaker_internet_ipv4() {
    char ipv4[16];
    memset(ipv4, 0, sizeof(ipv4));
    unsigned o1 = cfaker_random_uint(0, 255);
    unsigned o2 = cfaker_random_uint(0, 255);
    unsigned o3 = cfaker_random_uint(0, 255);
    unsigned o4 = cfaker_random_uint(0, 255);
    sprintf(ipv4, "%u.%u.%u.%u", o1, o2, o3, o4);
    return cfaker_format_replace_string(ipv4, NULL, 0);
}

const char* cfaker_internet_ipv6() {
    char ipv6[40];
    memset(ipv6, 0, sizeof(ipv6));
    uint16_t parts[8];
    for (int i = 0; i < 8; i++) {
        parts[i] = (uint16_t)cfaker_random_uint(0, 0xFFFF);
    }
    sprintf(ipv6, "%x:%x:%x:%x:%x:%x:%x:%x", parts[0], parts[1], parts[2], parts[3], parts[4], parts[5], parts[6],
            parts[7]);
    return cfaker_format_replace_string(ipv6, NULL, 0);
}

const char* cfaker_internet_mac() {
    unsigned char mac[6];
    // Set the second least significant bit to 0 and the least significant bit to 1
    int rand_byte = cfaker_random_uint(0, 255);
    mac[0] = (unsigned char)((rand_byte & 0xFE) | 0x02);
    for (int i = 1; i < 6; i++) {
        mac[i] = cfaker_random_uint(0, 255);
    }
    char mac_address[18];
    memset(mac_address, 0, sizeof(mac_address));
    snprintf(mac_address, sizeof(mac_address), "%02x:%02x:%02x:%02x:%02x:%02x", mac[0], mac[1], mac[2], mac[3], mac[4],
             mac[5]);
    return cfaker_format_replace_string(mac_address, NULL, 0);
}

uint16_t cfaker_internet_port() {
    return cfaker_random_uint(1, 65535);
}
