#ifndef __CFAKER_PERSON_H__
#define __CFAKER_PERSON_H__

/**
 * @brief Enumeration for person gender options.
 */
enum cfaker_person_gender {
    CFAKER_PERSON_FEMALE, /**< Female gender. */
    CFAKER_PERSON_MALE,   /**< Male gender. */
    CFAKER_PERSON_ANY,    /**< Any gender (random selection). */
};

/**
 * @brief Returns a random first name based on the specified gender.
 *
 * @param gender The gender for the first name selection.
 *
 * @returns A pointer to a constant string representing the first name.
 *
 * @code
 * cfaker_person_first_name(CFAKER_PERSON_FEMALE); // "Emily"
 * cfaker_person_first_name(CFAKER_PERSON_MALE); // "John"
 * @endcode
 */
const char* cfaker_person_first_name(enum cfaker_person_gender gender);

/**
 * @brief Returns a random last name.
 *
 * @returns A pointer to a constant string representing the last name.
 *
 * @code
 * cfaker_person_last_name(); // "Smith"
 * @endcode
 */
const char* cfaker_person_last_name();

/**
 * @brief Returns a random name prefix based on the specified gender.
 *
 * @param gender The gender for the prefix selection.
 *
 * @returns A pointer to a constant string representing the name prefix.
 *
 * @code
 * cfaker_person_prefix(CFAKER_PERSON_FEMALE); // "Mrs."
 * cfaker_person_prefix(CFAKER_PERSON_MALE); // "Mr."
 * @endcode
 */
const char* cfaker_person_prefix(enum cfaker_person_gender gender);

/**
 * @brief Returns a random name suffix based on the specified gender.
 *
 * @param gender The gender for the suffix selection.
 *
 * @returns A pointer to a constant string representing the name suffix.
 *
 * @code
 * cfaker_person_suffix(CFAKER_PERSON_ANY); // "Jr."
 * @endcode
 */
const char* cfaker_person_suffix(enum cfaker_person_gender gender);

/**
 * @brief Returns a random full name based on the specified gender.
 *
 * @param gender The gender for the full name selection.
 *
 * @returns A pointer to a constant string representing the full name.
 *
 * @code
 * cfaker_person_full_name(CFAKER_PERSON_FEMALE); // "Emily Johnson"
 * cfaker_person_full_name(CFAKER_PERSON_MALE); // "Michael Brown"
 * @endcode
 */
const char* cfaker_person_full_name(enum cfaker_person_gender gender);

#endif
