#ifndef __CFAKER_H__
#define __CFAKER_H__

#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_bank.h"
#include "providers/cfaker_book.h"
#include "providers/cfaker_datetime.h"
#include "providers/cfaker_job.h"
#include "providers/cfaker_person.h"

/**
 * @brief Initialize the cfaker library.
 * This function sets up necessary components and initializes random generators.
 *
 * @returns 0 on success, 1 on failure.
 *
 * @code
 * cfaker_init(); // Initializes cfaker library
 * @endcode
 */
int cfaker_init();

/**
 * @brief Free the resources allocated by the cfaker library.
 * This function releases all memory and handles cleanup.
 *
 * @code
 * cfaker_free(); // Frees all resources used by cfaker
 * @endcode
 */
void cfaker_free();

#endif  // __CFAKER_H__
