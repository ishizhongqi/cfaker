#ifndef __CFAKER_INTERNET_H__
#define __CFAKER_INTERNET_H__

#include <stdint.h>

/**
 * @brief Flag to include lowercase letters (a-z) in generated strings.
 */
#define CFAKER_INTERNET_LOWERCASE (1 << 0)

/**
 * @brief Flag to include uppercase letters (A-Z) in generated strings.
 */
#define CFAKER_INTERNET_UPPERCASE (1 << 1)

/**
 * @brief Flag to include numbers (0-9) in generated strings.
 */
#define CFAKER_INTERNET_NUMBER (1 << 2)

/**
 * @brief Flag to include period (.) in generated strings.
 */
#define CFAKER_INTERNET_PERIOD (1 << 3)

/**
 * @brief Flag to include underscore (_) in generated strings.
 */
#define CFAKER_INTERNET_UNDERSCORE (1 << 4)

/**
 * @brief Flag to include hyphen (-) in generated strings.
 */
#define CFAKER_INTERNET_HYPHEN (1 << 5)

/**
 * @brief Flag to include special characters (!@#$%^&*) in generated strings.
 */
#define CFAKER_INTERNET_SPECIAL (1 << 6)

/**
 * @brief Flag to include locale-specific characters (e.g., Chinese characters for zh_CN).
 */
#define CFAKER_INTERNET_LOCALE (1 << 7)

/**
 * @brief Returns a random top-level domain (TLD).
 *
 * @return Pointer to a null-terminated string containing the TLD.
 *
 * @code
 * cfaker_internet_tlds() // "com"
 * @endcode
 */
const char* cfaker_internet_tlds();

/**
 * @brief Returns a random domain name with specified number of levels.
 *
 * @param levels Number of domain levels (e.g., 1 for "example.com", 2 for "sub.example.com").
 * @return Pointer to a null-terminated string containing the domain name.
 *
 * @code
 * cfaker_internet_domain(1) // "example.com"
 * cfaker_internet_domain(2) // "sub.example.com"
 * @endcode
 */
const char* cfaker_internet_domain(uint32_t levels);

/**
 * @brief Returns a random username.
 *
 * @return Pointer to a null-terminated string containing the username.
 *
 * @code
 * cfaker_internet_username() // "john_doe123"
 * @endcode
 */
const char* cfaker_internet_username();

/**
 * @brief Returns a random password with specified length and character types.
 *
 * @param length Length of the generated password.
 * @param char_flags Bitwise flags to specify allowed character types (e.g., CFAKER_INTERNET_LOWERCASE).
 * @return Pointer to a null-terminated string containing the password.
 *
 * @code
 * cfaker_internet_password(12, CFAKER_INTERNET_LOWERCASE | CFAKER_INTERNET_NUMBER) // "abc123def456"
 * @endcode
 */
const char* cfaker_internet_password(uint32_t length, uint8_t char_flags);

/**
 * @brief Returns a random email address with the specified domain.
 *
 * @param domain Domain name to use in the email address.
 * @return Pointer to a null-terminated string containing the email address.
 *
 * @code
 * cfaker_internet_email("example.com") // "john.doe@example.com"
 * @endcode
 */
const char* cfaker_internet_email(const char* domain);

/**
 * @brief Returns a random URL with the specified schemes.
 *
 * @param schemes URL scheme (e.g., "http", "https").
 * @return Pointer to a null-terminated string containing the URL.
 *
 * @code
 * cfaker_internet_url("https") // "https://example.com"
 * @endcode
 */
const char* cfaker_internet_url(const char* schemes);

/**
 * @brief Returns a random IPv4 address.
 *
 * @return Pointer to a null-terminated string containing the IPv4 address.
 *
 * @code
 * cfaker_internet_ipv4() // "192.168.1.1"
 * @endcode
 */
const char* cfaker_internet_ipv4();

/**
 * @brief Returns a random IPv6 address.
 *
 * @return Pointer to a null-terminated string containing the IPv6 address.
 *
 * @code
 * cfaker_internet_ipv6() // "2001:0db8:85a3:0000:0000:8a2e:0370:7334"
 * @endcode
 */
const char* cfaker_internet_ipv6();

/**
 * @brief Returns a random MAC address.
 *
 * @return Pointer to a null-terminated string containing the MAC address.
 *
 * @code
 * cfaker_internet_mac() // "00:1A:2B:3C:4D:5E"
 * @endcode
 */
const char* cfaker_internet_mac();

/**
 * @brief Returns a random network port number.
 *
 * @return 16-bit unsigned integer representing the port number.
 *
 * @code
 * cfaker_internet_port() // 8080
 * @endcode
 */
uint16_t cfaker_internet_port();

#endif  // __CFAKER_INTERNET_H__
