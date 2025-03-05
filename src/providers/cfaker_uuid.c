#include "cfaker_format.h"
#include "cfaker_random.h"

#include "providers/cfaker_uuid.h"

#include <stdio.h>
#include <time.h>

#if defined(_WIN32)
#include <windows.h>
#else
#include <sys/time.h>
#include <unistd.h>
#endif

/* Helper: Get current time in 100-nanosecond intervals since 1582-10-15 */
static uint64_t get_time_v1() {
    uint64_t epoch_1582 = 122192928000000000ULL;  // 1582-10-15 to 1970-01-01 in 100ns
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    uint64_t unix_ns = (uint64_t)ts.tv_sec * 10000000ULL + ts.tv_nsec / 100;
    return unix_ns + epoch_1582;
}

/* Helper: Fake MAC address (random) */
static void get_fake_mac(uint8_t* mac) {
    for (int i = 0; i < 6; i++) {
        mac[i] = (uint8_t)cfaker_random_uint(0, 255);
    }
}

const char* cfaker_uuid_v1() {
    uint64_t time = get_time_v1();
    uint16_t clock_seq = (uint16_t)cfaker_random_uint(0, 0x3FFF);  // 14 bits
    uint8_t mac[6];
    get_fake_mac(mac);

    uint32_t time_low = (uint32_t)(time & 0xFFFFFFFF);
    uint16_t time_mid = (uint16_t)((time >> 32) & 0xFFFF);
    uint16_t time_hi = (uint16_t)((time >> 48) & 0x0FFF) | (1 << 12);  // Version 1

    char uuid[37];
    snprintf(uuid, sizeof(uuid), "%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x", time_low, time_mid, time_hi,
             (clock_seq & 0x3FFF) | 0x8000,  // Variant 10xx
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return cfaker_format_replace_string(uuid, NULL, 0);  // Copy to cfaker buffer
}

const char* cfaker_uuid_v4() {
    uint64_t rand1 = cfaker_random_uint(0, 0xFFFFFFFF);                  // 32 bits
    uint16_t rand2 = (uint16_t)cfaker_random_uint(0, 0xFFFF);            // 16 bits
    uint16_t rand3 = (cfaker_random_uint(0, 0xFFF) & 0x0FFF) | 0x4000;   // 16 bits, version 4
    uint16_t rand4 = (cfaker_random_uint(0, 0x3FFF) & 0x3FFF) | 0x8000;  // 16 bits, variant 10xx
    uint64_t rand5 = ((uint64_t)cfaker_random_uint(0, 0xFFFF) << 32) | cfaker_random_uint(0, 0xFFFFFFFF);  // 48 bits

    char uuid[37];
    snprintf(uuid, sizeof(uuid), "%08llx-%04x-%04x-%04x-%012llx", rand1, rand2, rand3, rand4, rand5);
    return cfaker_format_replace_string(uuid, NULL, 0);
}

const char* cfaker_uuid_v7() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    uint64_t unix_ms = (uint64_t)ts.tv_sec * 1000ULL + ts.tv_nsec / 1000000ULL;

    uint32_t time_high = (uint32_t)(unix_ms >> 16);                         // 32 bits
    uint16_t time_low = (uint16_t)(unix_ms & 0xFFFF);                       // 16 bits
    uint16_t rand_a = (cfaker_random_uint(0, 0xFFF) & 0x0FFF) | (7 << 12);  // 12 bits random + version 7
    uint16_t rand_b = (cfaker_random_uint(0, 0xFFFF) & 0x3FFF) | 0x8000;    // 14 bits random + variant 10xx
    uint64_t rand_c = ((uint64_t)cfaker_random_uint(0, 0xFFFF) << 32) | cfaker_random_uint(0, 0xFFFFFFFF);  // 48 bits

    char uuid[37];
    snprintf(uuid, sizeof(uuid), "%08x-%04x-%04x-%04x-%012llx", time_high, time_low, rand_a, rand_b, rand_c);
    return cfaker_format_replace_string(uuid, NULL, 0);
}
