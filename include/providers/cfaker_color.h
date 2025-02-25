#ifndef __CFAKER_COLOR_H__
#define __CFAKER_COLOR_H__

#include <stdbool.h>

#include "providers/cfaker_number.h"

/**
 * @brief Returns a random color name.
 *
 * @returns A pointer to a constant string representing the color name.
 *
 * @code
 * cfaker_color_name(); // "Blue"
 * @endcode
 */
const char* cfaker_color_name();

/**
 * @brief Returns a random RGB color string.
 *
 * @param include_alpha If true, includes an alpha (opacity) value in the output.
 * @returns A pointer to a constant string representing the RGB(A) color.
 *
 * @code
 * cfaker_color_rgb(false); // "rgb(123, 45, 67)"
 * cfaker_color_rgb(true);  // "rgba(123, 45, 67, 0.75)"
 * @endcode
 */
const char* cfaker_color_rgb(bool include_alpha);

/**
 * @brief Returns a random hexadecimal color string.
 *
 * @param upper If true, returns uppercase hex letters.
 * @param hex_prefix Specifies the prefix format (e.g., none, "0x", or "#").
 * @param include_alpha If true, includes an alpha (opacity) value in the output.
 * @returns A pointer to a constant string representing the hex color.
 *
 * @code
 * cfaker_color_hex(true, CFAKER_NUMBER_HEX_HASH, false); // "#FF5733"
 * cfaker_color_hex(false, CFAKER_NUMBER_HEX_ZeroX, true);  // "0xff5733cc"
 * @endcode
 */
const char* cfaker_color_hex(bool upper, enum cfaker_number_hex_prefix hex_prefix, bool include_alpha);

/**
 * @brief Returns a random HSL color string.
 *
 * @param include_alpha If true, includes an alpha (opacity) value in the output.
 * @returns A pointer to a constant string representing the HSL(A) color.
 *
 * @code
 * cfaker_color_hsl(false); // "hsl(210, 50%, 60%)"
 * cfaker_color_hsl(true);  // "hsla(210, 50%, 60%, 0.85)"
 * @endcode
 */
const char* cfaker_color_hsl(bool include_alpha);

/**
 * @brief Returns a random LCH color string.
 *
 * @param include_alpha If true, includes an alpha (opacity) value in the output.
 * @returns A pointer to a constant string representing the LCH(A) color.
 *
 * @code
 * cfaker_color_lch(false); // "lch(75%, 50, 200)"
 * cfaker_color_lch(true);  // "lcha(75%, 50, 200, 0.9)"
 * @endcode
 */
const char* cfaker_color_lch(bool include_alpha);

/**
 * @brief Returns a random CMYK color string.
 *
 * @returns A pointer to a constant string representing the CMYK color.
 *
 * @code
 * cfaker_color_cmyk(); // "cmyk(30%, 20%, 10%, 5%)"
 * @endcode
 */
const char* cfaker_color_cmyk();

/**
 * @brief Returns a random Lab color string.
 *
 * @returns A pointer to a constant string representing the Lab color.
 *
 * @code
 * cfaker_color_lab(); // "lab(60, 20, -30)"
 * @endcode
 */
const char* cfaker_color_lab();

/**
 * @brief Returns a random HSB color string.
 *
 * @returns A pointer to a constant string representing the HSB color.
 *
 * @code
 * cfaker_color_hsb(); // "hsb(120, 50%, 80%)"
 * @endcode
 */
const char* cfaker_color_hsb();

/**
 * @brief Returns a random HSV color string.
 *
 * @returns A pointer to a constant string representing the HSV color.
 *
 * @code
 * cfaker_color_hsv(); // "hsv(180, 40%, 90%)"
 * @endcode
 */
const char* cfaker_color_hsv();

/**
 * @brief Returns a random HWB color string.
 *
 * @returns A pointer to a constant string representing the HWB color.
 *
 * @code
 * cfaker_color_hwb(); // "hwb(240, 30%, 10%)"
 * @endcode
 */
const char* cfaker_color_hwb();

/**
 * @brief Returns a random YUV color string.
 *
 * @returns A pointer to a constant string representing the YUV color.
 *
 * @code
 * cfaker_color_yuv(); // "yuv(90, 50, 30)"
 * @endcode
 */
const char* cfaker_color_yuv();

#endif
