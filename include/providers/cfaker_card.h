#ifndef __CFAKER_CARD_H__
#define __CFAKER_CARD_H__

/**
 * @brief Enumeration of card types.
 */
enum cfaker_card_type {
    CFAKER_CARD_DEBIT,  /**< Debit card type. */
    CFAKER_CARD_CREDIT, /**< Credit card type. */
};

/**
 * @brief Returns a random primary account number (PAN) for a card.
 *
 * @return Pointer to a null-terminated string containing the card PAN.
 *
 * @code
 * cfaker_card_pan() // "4532015112830366"
 * @endcode
 */
const char* cfaker_card_pan();

/**
 * @brief Returns a random CVV2 code for a card.
 *
 * @return Pointer to a null-terminated string containing the CVV2 code.
 *
 * @code
 * cfaker_card_cvv2() // "123"
 * @endcode
 */
const char* cfaker_card_cvv2();

/**
 * @brief Returns a random card issuer name.
 *
 * @return Pointer to a null-terminated string containing the card issuer name.
 *
 * @code
 * cfaker_card_issuer() // "Visa"
 * @endcode
 */
const char* cfaker_card_issuer();

#endif /* __CFAKER_CARD_H__ */
