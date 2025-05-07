#ifndef __CFAKER_INTERNET_H__
#define __CFAKER_INTERNET_H__

#include <stdint.h>

#define CFAKER_INTERNET_LOWERLETTER (1 << 0) /* a-z */
#define CFAKER_INTERNET_UPPERLETTER (1 << 1) /* A-Z */
#define CFAKER_INTERNET_NUMBER (1 << 2)      /* 0-9 */
#define CFAKER_INTERNET_PERIOD (1 << 3)      /* . */
#define CFAKER_INTERNET_UNDERSCORE (1 << 4)  /* _ */
#define CFAKER_INTERNET_HYPHEN (1 << 5)      /* - */
#define CFAKER_INTERNET_SPECIAL (1 << 6)     /* !@#$%^&* */
#define CFAKER_INTERNET_LOCALE (1 << 7)      /* locale characters, example(zh_CN): 汉字 */

const char* cfaker_internet_tlds();

const char* cfaker_internet_domain(uint32_t level);

const char* cfaker_internet_username();

const char* cfaker_internet_password(uint32_t length, uint8_t char_flags);

const char* cfaker_internet_email(const char* domain);

const char* cfaker_internet_url(const char* schemes);

const char* cfaker_internet_ipv4();

const char* cfaker_internet_ipv6();

const char* cfaker_internet_mac();

const char* cfaker_internet_port();

#endif
