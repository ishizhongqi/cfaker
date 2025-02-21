#ifndef __CFAKER_BOOK_H__
#define __CFAKER_BOOK_H__

/**
 * @brief Returns a random book title.
 *
 * @returns A pointer to a constant string representing the book title.
 *
 * @code
 * cfaker_book_title(); // "The Great Adventure"
 * @endcode
 */
const char* cfaker_book_title();

/**
 * @brief Returns a random book author.
 *
 * @returns A pointer to a constant string representing the book author.
 *
 * @code
 * cfaker_book_author(); // "John Doe"
 * @endcode
 */
const char* cfaker_book_author();

/**
 * @brief Returns a random book genre.
 *
 * @returns A pointer to a constant string representing the book genre.
 *
 * @code
 * cfaker_book_genre(); // "Science Fiction"
 * @endcode
 */
const char* cfaker_book_genre();

/**
 * @brief Returns a random book publisher.
 *
 * @returns A pointer to a constant string representing the book publisher.
 *
 * @code
 * cfaker_book_publisher(); // "Penguin Random House"
 * @endcode
 */
const char* cfaker_book_publisher();

/**
 * @brief Returns a random book format.
 *
 * @returns A pointer to a constant string representing the book format.
 *
 * @code
 * cfaker_book_format(); // "Hardcover"
 * @endcode
 */
const char* cfaker_book_format();

/**
 * @brief Returns a random book series name.
 *
 * @returns A pointer to a constant string representing the book series name.
 *
 * @code
 * cfaker_book_series(); // "The Chronicles of Time"
 * @endcode
 */
const char* cfaker_book_series();

#endif
