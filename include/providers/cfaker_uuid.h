#ifndef __CFAKER_UUID_H__
#define __CFAKER_UUID_H__

/**
 * @brief Returns a random UUID v1 (time-based with MAC address).
 *
 * @returns A pointer to a constant string representing the UUID v1.
 *
 * @code
 * cfaker_uuid_v1(); // "550e8400-e29b-11d4-a716-446655440000"
 * @endcode
 */
const char* cfaker_uuid_v1();

/**
 * @brief Returns a random UUID v4 (randomly generated).
 *
 * @returns A pointer to a constant string representing the UUID v4.
 *
 * @code
 * cfaker_uuid_v4(); // "123e4567-e89b-41d4-a716-426655440000"
 * @endcode
 */
const char* cfaker_uuid_v4();

/**
 * @brief Returns a random UUID v7 (Unix timestamp-based).
 *
 * @returns A pointer to a constant string representing the UUID v7.
 *
 * @code
 * cfaker_uuid_v7(); // "018f8c40-1234-71d4-a716-446655440000"
 * @endcode
 */
const char* cfaker_uuid_v7();

#endif /* __CFAKER_UUID_H__ */
