/*******************************************************************************
 * Size: 8 px
 * Bpp: 1
 * Opts: --bpp 1 --size 8 --no-compress --stride 1 --align 1 --font led-counter-7.regular.ttf --range 0-255 --format lvgl -o font.c
 ******************************************************************************/

#include <stdint.h>

#ifndef FONT
#define FONT 

typedef struct {
    uint32_t bitmap_index;          /**< Start index of the bitmap. A font can be max 4 GB.*/
    uint32_t adv_w;                 /**< Draw the next glyph after this width. 28.4 format (real_value * 16 is stored).*/
    uint16_t box_w;                 /**< Width of the glyph's bounding box*/
    uint16_t box_h;                 /**< Height of the glyph's bounding box*/
    int16_t ofs_x;                  /**< x offset of the bounding box*/
    int16_t ofs_y;  
} glyph_desc_t;


typedef struct {
    uint32_t range_start;    /* First Unicode character */
    uint32_t range_length;   /* Number of characters in range */
    uint16_t glyph_id_start; /* ID of the first glyph in this range */
    const uint8_t* unicode_list; /* Optional: list of unicode offsets */
    const uint16_t* glyph_id_ofs_list; /* Optional: list of glyph ID offsets */
    uint8_t list_length;     /* Number of elements in unicode_list or glyph_id_ofs_list */
} cmap_t;


/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf4,

    /* U+0022 "\"" */
    0x5a,

    /* U+0023 "#" */
    0x16, 0x16, 0x7f, 0x24, 0xfe, 0x50, 0x50,

    /* U+0024 "$" */
    0x27, 0xa7, 0xf2,

    /* U+0025 "%" */
    0x4a, 0xa5, 0xa, 0x55, 0x20,

    /* U+0026 "&" */
    0x4a, 0xad, 0xa5,

    /* U+0027 "'" */
    0x60,

    /* U+0028 "(" */
    0x72, 0x48, 0xc0,

    /* U+0029 ")" */
    0xc4, 0x93, 0x80,

    /* U+002A "*" */
    0xab, 0xaa, 0x40,

    /* U+002B "+" */
    0x21, 0x9, 0xf2, 0x10,

    /* U+002C "," */
    0x60,

    /* U+002D "-" */
    0xc0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x12, 0x24, 0x48,

    /* U+0030 "0" */
    0x69, 0x99, 0x96,

    /* U+0031 "1" */
    0x59, 0x25, 0xc0,

    /* U+0032 "2" */
    0x69, 0x16, 0x8f,

    /* U+0033 "3" */
    0x69, 0x17, 0x96,

    /* U+0034 "4" */
    0x75, 0x9f, 0x11,

    /* U+0035 "5" */
    0x78, 0x87, 0x96,

    /* U+0036 "6" */
    0x24, 0x8f, 0x96,

    /* U+0037 "7" */
    0xe1, 0x12, 0x44,

    /* U+0038 "8" */
    0x69, 0x9f, 0x96,

    /* U+0039 "9" */
    0x69, 0x97, 0x24,

    /* U+003A ":" */
    0xa0,

    /* U+003B ";" */
    0x46,

    /* U+003C "<" */
    0x64,

    /* U+003D "=" */
    0xf8, 0x3e,

    /* U+003E ">" */
    0x98,

    /* U+003F "?" */
    0x69, 0x16, 0x44,

    /* U+0040 "@" */
    0x39, 0x19, 0xeb, 0x95, 0x3, 0x0,

    /* U+0041 "A" */
    0xe9, 0x9f, 0x99,

    /* U+0042 "B" */
    0xe9, 0x8b, 0x9e,

    /* U+0043 "C" */
    0x7c, 0x88, 0xc7,

    /* U+0044 "D" */
    0xe9, 0x99, 0x9e,

    /* U+0045 "E" */
    0x78, 0x8e, 0x87,

    /* U+0046 "F" */
    0x78, 0x8e, 0x88,

    /* U+0047 "G" */
    0x7c, 0x8b, 0xd6,

    /* U+0048 "H" */
    0x99, 0xbd, 0x99,

    /* U+0049 "I" */
    0xe9, 0x25, 0xc0,

    /* U+004A "J" */
    0x11, 0x11, 0xb6,

    /* U+004B "K" */
    0x99, 0xae, 0x99,

    /* U+004C "L" */
    0x88, 0x88, 0x87,

    /* U+004D "M" */
    0x55, 0x63, 0x18, 0xc4,

    /* U+004E "N" */
    0x99, 0xdb, 0x99,

    /* U+004F "O" */
    0x69, 0x99, 0x96,

    /* U+0050 "P" */
    0xe9, 0x9e, 0x88,

    /* U+0051 "Q" */
    0x69, 0x99, 0xa5,

    /* U+0052 "R" */
    0xe8, 0x9f, 0x99,

    /* U+0053 "S" */
    0x69, 0x87, 0x96,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10,

    /* U+0055 "U" */
    0x99, 0x99, 0x96,

    /* U+0056 "V" */
    0x99, 0x96, 0x60,

    /* U+0057 "W" */
    0x8c, 0x63, 0x5a, 0xa8,

    /* U+0058 "X" */
    0x99, 0x66, 0x99,

    /* U+0059 "Y" */
    0x8c, 0x54, 0x42, 0x10,

    /* U+005A "Z" */
    0xf1, 0x24, 0x8f,

    /* U+005B "[" */
    0xf2, 0x49, 0xc0,

    /* U+005C "\\" */
    0x82, 0x10, 0x61, 0x4,

    /* U+005D "]" */
    0xe4, 0x93, 0xc0,

    /* U+005E "^" */
    0x54,

    /* U+005F "_" */
    0xf0,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0x74, 0xa4, 0xd0,

    /* U+0062 "b" */
    0x88, 0xe9, 0x9e,

    /* U+0063 "c" */
    0x78, 0x87,

    /* U+0064 "d" */
    0x11, 0x79, 0x97,

    /* U+0065 "e" */
    0x6f, 0x87,

    /* U+0066 "f" */
    0x69, 0x8e, 0x88,

    /* U+0067 "g" */
    0x69, 0x97, 0x96,

    /* U+0068 "h" */
    0x88, 0xad, 0x99,

    /* U+0069 "i" */
    0xbc,

    /* U+006A "j" */
    0x20, 0x92, 0x6a,

    /* U+006B "k" */
    0x88, 0xae, 0xa9,

    /* U+006C "l" */
    0x92, 0x48, 0xc0,

    /* U+006D "m" */
    0x6d, 0x99,

    /* U+006E "n" */
    0x4a, 0x99,

    /* U+006F "o" */
    0x69, 0x96,

    /* U+0070 "p" */
    0xe9, 0x9e, 0x88,

    /* U+0071 "q" */
    0x79, 0x97, 0x11,

    /* U+0072 "r" */
    0x69, 0x88,

    /* U+0073 "s" */
    0x7f, 0x1f,

    /* U+0074 "t" */
    0x44, 0xf4, 0x53,

    /* U+0075 "u" */
    0x99, 0x96,

    /* U+0076 "v" */
    0x99, 0x64,

    /* U+0077 "w" */
    0x99, 0xd6,

    /* U+0078 "x" */
    0x97, 0x59,

    /* U+0079 "y" */
    0x99, 0x17, 0x96,

    /* U+007A "z" */
    0xf7, 0x87,

    /* U+007B "{" */
    0x34, 0x4c, 0x43,

    /* U+007C "|" */
    0xfe,

    /* U+007D "}" */
    0xc2, 0x23, 0x2c,

    /* U+007E "~" */
    0x5a,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xbc,

    /* U+00A2 "¢" */
    0x23, 0xe9, 0x47, 0x90,

    /* U+00A3 "£" */
    0x32, 0x51, 0xe6, 0x3c,

    /* U+00A5 "¥" */
    0x99, 0x6f, 0xf4,

    /* U+00A7 "§" */
    0x32, 0x51, 0x76, 0x82, 0x4c,

    /* U+00A8 "¨" */
    0xc0,

    /* U+00A9 "©" */
    0x38, 0x8a, 0x6d, 0x19, 0xa8, 0x8e, 0x0,

    /* U+00AA "ª" */
    0x76, 0xb0,

    /* U+00AB "«" */
    0x59, 0x50,

    /* U+00AE "®" */
    0x6d, 0xf6,

    /* U+00B0 "°" */
    0x55, 0x0,

    /* U+00B2 "²" */
    0xfb,

    /* U+00B3 "³" */
    0xf7,

    /* U+00B4 "´" */
    0x60,

    /* U+00B7 "·" */
    0x80,

    /* U+00B9 "¹" */
    0x59, 0x70,

    /* U+00BA "º" */
    0x56, 0xa0,

    /* U+00BB "»" */
    0x95, 0x90,

    /* U+00BF "¿" */
    0x20, 0x2e, 0x96,

    /* U+00C0 "À" */
    0x42, 0xe9, 0x9f, 0x99,

    /* U+00C1 "Á" */
    0x24, 0xe9, 0x9f, 0x99,

    /* U+00C2 "Â" */
    0x46, 0xe9, 0x9f, 0x99,

    /* U+00C3 "Ã" */
    0x5a, 0xe9, 0x9f, 0x99,

    /* U+00C4 "Ä" */
    0x6e, 0x99, 0xf9, 0x90,

    /* U+00C5 "Å" */
    0x46, 0xe9, 0x9f, 0x99,

    /* U+00C6 "Æ" */
    0xef, 0x22, 0x47, 0xe9, 0x11, 0xc0,

    /* U+00C7 "Ç" */
    0x7c, 0x88, 0xc7, 0x2, 0x20,

    /* U+00C8 "È" */
    0x42, 0x78, 0x8e, 0x87,

    /* U+00C9 "É" */
    0x24, 0x78, 0x8e, 0x87,

    /* U+00CA "Ê" */
    0x26, 0x78, 0x8e, 0x87,

    /* U+00CB "Ë" */
    0x67, 0x88, 0xe8, 0x70,

    /* U+00CC "Ì" */
    0x8b, 0xa4, 0x97,

    /* U+00CD "Í" */
    0x4b, 0xa4, 0x97,

    /* U+00CE "Î" */
    0x57, 0xa4, 0x97,

    /* U+00CF "Ï" */
    0xbd, 0x24, 0xb8,

    /* U+00D1 "Ñ" */
    0x5a, 0x99, 0xdb, 0x99,

    /* U+00D2 "Ò" */
    0x42, 0x69, 0x99, 0x96,

    /* U+00D3 "Ó" */
    0x24, 0x69, 0x99, 0x96,

    /* U+00D4 "Ô" */
    0x46, 0x69, 0x99, 0x96,

    /* U+00D5 "Õ" */
    0x5a, 0x69, 0x99, 0x96,

    /* U+00D6 "Ö" */
    0x66, 0x99, 0x99, 0x60,

    /* U+00D7 "×" */
    0x85, 0x23, 0xc, 0x4a, 0x10,

    /* U+00D8 "Ø" */
    0x35, 0x25, 0x9a, 0x4a, 0xc0,

    /* U+00D9 "Ù" */
    0x42, 0x99, 0x99, 0x96,

    /* U+00DA "Ú" */
    0x24, 0x99, 0x99, 0x96,

    /* U+00DB "Û" */
    0x46, 0x99, 0x99, 0x96,

    /* U+00DC "Ü" */
    0x69, 0x99, 0x99, 0x60,

    /* U+00DD "Ý" */
    0x33, 0x23, 0x15, 0x10, 0x84,

    /* U+00DF "ß" */
    0xe9, 0x9b, 0x9a,

    /* U+00E0 "à" */
    0x41, 0x0, 0xe9, 0x49, 0xa0,

    /* U+00E1 "á" */
    0x22, 0x0, 0xe9, 0x49, 0xa0,

    /* U+00E2 "â" */
    0x22, 0x80, 0xe9, 0x49, 0xa0,

    /* U+00E3 "ã" */
    0x53, 0x0, 0xe9, 0x49, 0xa0,

    /* U+00E4 "ä" */
    0x50, 0x1d, 0x29, 0x34,

    /* U+00E5 "å" */
    0x22, 0x88, 0xe9, 0x49, 0xa0,

    /* U+00E6 "æ" */
    0x7d, 0x7e, 0x83, 0xf0,

    /* U+00E7 "ç" */
    0x78, 0x87, 0x2, 0x20,

    /* U+00E8 "è" */
    0x42, 0x6, 0xf8, 0x70,

    /* U+00E9 "é" */
    0x24, 0x6, 0xf8, 0x70,

    /* U+00EA "ê" */
    0x46, 0x6, 0xf8, 0x70,

    /* U+00EB "ë" */
    0x60, 0x6f, 0x87,

    /* U+00EC "ì" */
    0xde,

    /* U+00ED "í" */
    0xde,

    /* U+00EE "î" */
    0x54, 0x24, 0x90,

    /* U+00EF "ï" */
    0xa1, 0x24, 0x80,

    /* U+00F1 "ñ" */
    0x5a, 0x4, 0xa9, 0x90,

    /* U+00F2 "ò" */
    0x42, 0x6, 0x99, 0x60,

    /* U+00F3 "ó" */
    0x24, 0x6, 0x99, 0x60,

    /* U+00F4 "ô" */
    0x46, 0x6, 0x99, 0x60,

    /* U+00F5 "õ" */
    0x5a, 0x6, 0x99, 0x60,

    /* U+00F6 "ö" */
    0x60, 0x69, 0x96,

    /* U+00F8 "ø" */
    0x16, 0xbd, 0xe0,

    /* U+00F9 "ù" */
    0x42, 0x9, 0x99, 0x60,

    /* U+00FA "ú" */
    0x24, 0x9, 0x99, 0x60,

    /* U+00FB "û" */
    0x46, 0x9, 0x99, 0x60,

    /* U+00FC "ü" */
    0x60, 0x99, 0x96,

    /* U+00FD "ý" */
    0x60, 0x99, 0x17, 0x96,

    /* U+00FF "ÿ" */
    0x60, 0x99, 0x17, 0x96
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const glyph_desc_t glyph_desc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 32, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 23, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 61, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 3, .adv_w = 112, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 100, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 21, .adv_w = 36, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 22, .adv_w = 49, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 49, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 74, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 31, .adv_w = 100, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 36, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 36, .adv_w = 36, .box_w = 2, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 37, .adv_w = 23, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 49, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 68, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 23, .box_w = 1, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 36, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 73, .adv_w = 36, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 74, .adv_w = 97, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 36, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 49, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 72, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 74, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 73, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 74, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 72, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 49, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 97, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 49, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 49, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 179, .adv_w = 61, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 180, .adv_w = 118, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 181, .adv_w = 87, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 69, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 200, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 23, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 38, .box_w = 3, .box_h = 8, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 207, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 49, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 222, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 225, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 236, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 243, .adv_w = 74, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 61, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 23, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 61, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 61, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 253, .adv_w = 32, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 23, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 74, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 87, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 263, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 87, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 271, .adv_w = 123, .box_w = 2, .box_h = 1, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 272, .adv_w = 113, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 62, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 281, .adv_w = 74, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 61, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 285, .adv_w = 49, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 287, .adv_w = 49, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 288, .adv_w = 49, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 289, .adv_w = 118, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 290, .adv_w = 23, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 291, .adv_w = 49, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 293, .adv_w = 61, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 295, .adv_w = 74, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 300, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 304, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 125, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 74, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 335, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 343, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 49, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 49, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 49, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 49, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 367, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 100, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 392, .adv_w = 100, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 72, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 431, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 87, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 112, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 454, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 458, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 23, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 23, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 23, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 23, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 501, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 504, .adv_w = 87, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 515, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 74, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 526, .adv_w = 74, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_1[] = {
    0, 1, 2, 3, 0, 4, 0, 5,
    6, 7, 8, 9, 0, 0, 10, 0,
    11, 0, 12, 13, 14, 0, 0, 15,
    0, 16, 17, 18, 0, 0, 0, 19,
    20, 21, 22, 23, 24, 25, 26, 27,
    28, 29, 30, 31, 32, 33, 34, 35,
    0, 36, 37, 38, 39, 40, 41, 42,
    43, 44, 45, 46, 47, 48, 0, 49,
    50, 51, 52, 53, 54, 55, 56, 57,
    58, 59, 60, 61, 62, 63, 64, 65,
    0, 66, 67, 68, 69, 70, 71, 0,
    72, 73, 74, 75, 76, 77, 0, 78
};

/*Collect the unicode lists and glyph_id offsets*/
static const cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0,
    },
    {
        .range_start = 160, .range_length = 96, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 96,
    }
};



#endif
