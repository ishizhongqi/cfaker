#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_color.h"
#include "providers/data/cfaker_color_data.h"

#include <stdio.h>
#include <string.h>

static struct cfaker_color get_cfaker_color() {
    const enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_color_en_US;
    case zh_CN:
        return cfaker_color_zh_CN;
    default:
        break;
    }
    return cfaker_color_en_US;
}

const char* cfaker_color_name() {
    const struct cfaker_color color = get_cfaker_color();
    return color.names[cfaker_random_uint(0, color.name_count - 1)];
}

const char* cfaker_color_rgb(bool include_alpha) {
    char red[4];
    char green[4];
    char blue[4];
    char alpha[5];
    memset(red, 0, sizeof(red));
    memset(green, 0, sizeof(green));
    memset(blue, 0, sizeof(blue));
    memset(alpha, 0, sizeof(alpha));
    sprintf(red, "%u", cfaker_random_uint(0, 255));
    sprintf(green, "%u", cfaker_random_uint(0, 255));
    sprintf(blue, "%u", cfaker_random_uint(0, 255));
    sprintf(alpha, "%.2f", cfaker_random_double(0, 1.0));
    const struct cfaker_format_mapping mappings[] = {
        { "red", red },
        { "green", green },
        { "blue", blue },
        { "alpha", alpha },
    };
    if (include_alpha) {
        return cfaker_format_replace_string("rgba({red}, {green}, {blue}, {alpha})", mappings, 4);
    }
    return cfaker_format_replace_string("rgb({red}, {green}, {blue})", mappings, 4);
}

const char* cfaker_color_hex(bool upper, enum cfaker_number_hex_prefix hex_prefix, bool include_alpha) {
    return cfaker_number_hexadecimal_bylength(include_alpha ? 8 : 6, upper, hex_prefix);
}

const char* cfaker_color_hsl(bool include_alpha) {
    char hue[4];
    char saturation[4];
    char lightness[4];
    char alpha[5];
    memset(hue, 0, sizeof(hue));
    memset(saturation, 0, sizeof(saturation));
    memset(lightness, 0, sizeof(lightness));
    memset(alpha, 0, sizeof(alpha));
    sprintf(hue, "%u", cfaker_random_uint(0, 360));
    sprintf(saturation, "%u", cfaker_random_uint(0, 100));
    sprintf(lightness, "%u", cfaker_random_uint(0, 100));
    sprintf(alpha, "%.2f", cfaker_random_double(0, 1.0));
    const struct cfaker_format_mapping mappings[] = {
        { "hue", hue },
        { "saturation", saturation },
        { "lightness", lightness },
        { "alpha", alpha },
    };
    if (include_alpha) {
        return cfaker_format_replace_string("hsla({hue}, {saturation}%, {lightness}%, {alpha})", mappings, 4);
    }
    return cfaker_format_replace_string("hsl({hue}, {saturation}%, {lightness}%)", mappings, 4);
}

const char* cfaker_color_lch(bool include_alpha) {
    char luminance[4];
    char chroma[4];
    char hue[4];
    char alpha[5];
    memset(luminance, 0, sizeof(luminance));
    memset(chroma, 0, sizeof(chroma));
    memset(hue, 0, sizeof(hue));
    memset(alpha, 0, sizeof(alpha));
    sprintf(luminance, "%u", cfaker_random_uint(0, 360));
    sprintf(chroma, "%u", cfaker_random_uint(0, 100));
    sprintf(hue, "%u", cfaker_random_uint(0, 100));
    sprintf(alpha, "%.2f", cfaker_random_double(0, 1.0));
    const struct cfaker_format_mapping mappings[] = {
        { "luminance", luminance },
        { "chroma", chroma },
        { "hue", hue },
        { "alpha", alpha },
    };
    if (include_alpha) {
        return cfaker_format_replace_string("lcha({luminance}%, {chroma}, {hue}, {alpha})", mappings, 4);
    }
    return cfaker_format_replace_string("lch({luminance}%, {chroma}, {hue})", mappings, 4);
}

const char* cfaker_color_cmyk() {
    char cyan[5];
    char magenta[5];
    char yellow[5];
    char key[5];
    memset(cyan, 0, sizeof(cyan));
    memset(magenta, 0, sizeof(magenta));
    memset(yellow, 0, sizeof(yellow));
    memset(key, 0, sizeof(key));
    sprintf(cyan, "%.2f", cfaker_random_double(0, 1.0));
    sprintf(magenta, "%.2f", cfaker_random_double(0, 1.0));
    sprintf(yellow, "%.2f", cfaker_random_double(0, 1.0));
    sprintf(key, "%.2f", cfaker_random_double(0, 1.0));
    const struct cfaker_format_mapping mappings[] = {
        { "cyan", cyan },
        { "magenta", magenta },
        { "yellow", yellow },
        { "key", key },
    };
    return cfaker_format_replace_string("cmyk({cyan}%, {magenta}%, {yellow}%, {key}%)", mappings, 4);
}

const char* cfaker_color_lab() {
    char lightness[6];
    char red_green[7];
    char blue_yellow[7];
    memset(lightness, 0, sizeof(lightness));
    memset(red_green, 0, sizeof(red_green));
    memset(blue_yellow, 0, sizeof(blue_yellow));
    sprintf(lightness, "%.2f", cfaker_random_double(0, 100.0));
    sprintf(red_green, "%.2f", cfaker_random_double(-128.0, 128.0));
    sprintf(blue_yellow, "%.2f", cfaker_random_double(-128.0, 128.0));
    const struct cfaker_format_mapping mappings[] = {
        { "lightness", lightness },
        { "red_green", red_green },
        { "blue_yellow", blue_yellow },
    };
    return cfaker_format_replace_string("lab({lightness}, {red_green}, {blue_yellow})", mappings, 3);
}

const char* cfaker_color_hsb() {
    char hue[4];
    char saturation[4];
    char brightness[4];
    memset(hue, 0, sizeof(hue));
    memset(saturation, 0, sizeof(saturation));
    memset(brightness, 0, sizeof(brightness));
    sprintf(hue, "%u", cfaker_random_uint(0, 360));
    sprintf(saturation, "%u", cfaker_random_uint(0, 100));
    sprintf(brightness, "%u", cfaker_random_uint(0, 100));
    const struct cfaker_format_mapping mappings[] = {
        { "hue", hue },
        { "saturation", saturation },
        { "brightness", brightness },
    };
    return cfaker_format_replace_string("hsb({hue}, {saturation}%, {brightness}%)", mappings, 3);
}

const char* cfaker_color_hsv() {
    char hue[4];
    char saturation[4];
    char value[4];
    memset(hue, 0, sizeof(hue));
    memset(saturation, 0, sizeof(saturation));
    memset(value, 0, sizeof(value));
    sprintf(hue, "%u", cfaker_random_uint(0, 360));
    sprintf(saturation, "%u", cfaker_random_uint(0, 100));
    sprintf(value, "%u", cfaker_random_uint(0, 100));
    const struct cfaker_format_mapping mappings[] = {
        { "hue", hue },
        { "saturation", saturation },
        { "value", value },
    };
    return cfaker_format_replace_string("hsv({hue}, {saturation}%, {value}%)", mappings, 3);
}

const char* cfaker_color_hwb() {
    char hue[4];
    char whiteness[4];
    char blackness[4];
    memset(hue, 0, sizeof(hue));
    memset(whiteness, 0, sizeof(whiteness));
    memset(blackness, 0, sizeof(blackness));
    sprintf(hue, "%u", cfaker_random_uint(0, 360));
    sprintf(whiteness, "%u", cfaker_random_uint(0, 100));
    sprintf(blackness, "%u", cfaker_random_uint(0, 100));
    const struct cfaker_format_mapping mappings[] = {
        { "hue", hue },
        { "whiteness", whiteness },
        { "blackness", blackness },
    };
    return cfaker_format_replace_string("hwb({hue}, {whiteness}%, {blackness}%)", mappings, 3);
}

const char* cfaker_color_yuv() {
    char luminance[4];
    char chrominance_blue[4];
    char chrominance_red[4];
    memset(luminance, 0, sizeof(luminance));
    memset(chrominance_blue, 0, sizeof(chrominance_blue));
    memset(chrominance_red, 0, sizeof(chrominance_red));
    sprintf(luminance, "%u", cfaker_random_uint(0, 255));
    sprintf(chrominance_blue, "%u", cfaker_random_uint(0, 255));
    sprintf(chrominance_red, "%u", cfaker_random_uint(0, 255));
    const struct cfaker_format_mapping mappings[] = {
        { "luminance", luminance },
        { "chrominance_blue", chrominance_blue },
        { "chrominance_red", chrominance_red },
    };
    return cfaker_format_replace_string("hwb({luminance}, {chrominance_blue}, {chrominance_red})", mappings, 3);
}
