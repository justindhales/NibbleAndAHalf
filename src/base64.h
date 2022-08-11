/*

  https://github.com/superwills/NibbleAndAHalf
  base64.h -- Fast base64 encoding and decoding.
  version 1.0.1, Feb 1, 2022 812a

  Copyright (C) 2013 William Sherif

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  William Sherif
  will.sherif@gmail.com

  YWxsIHlvdXIgYmFzZSBhcmUgYmVsb25nIHRvIHVz

  Edited by justindhales (2022)
  Added base64_block() and unbase64_block() functions.
  These functions operate on up to three bytes of input data and do not
  dynamically allocate memory.

*/
#ifndef NIBBLEANDAHALF_SRC_BASE64_H
#define NIBBLEANDAHALF_SRC_BASE64_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INVALID_BASE64 (-1000)

typedef struct {
  unsigned char c[4];
  int len;
} base64_block_encoded_t;

typedef struct {
  uint8_t b[3];
  int len;
} base64_block_data_t;

// The COMPILE-TIME SETTING SAFEBASE64 is really important.
// You need to decide if PARANOIA is more important to you than speed.
//
// SAFEBASE64: Remove this def to NOT check the validity of base64 ascii strings
// before unbase64'ing that string.  If you don't #define SAFEBASE64,
// then the program assumes that all characters in the string sent to unbase64()
// are in the base64 alphabet.  As such if a character is NOT in the base64
// alphabet your data will be wrong (it will be turned to 0 (as if it were just
// a base64 'A')). Removing this test greatly speeds up unbase64'ing (by about
// 3-4x).
#define SAFEBASE64
#define isMultipleOf(a, x) (!((a) % x))

// Converts any binary data to base64 characters.
// Length of the resultant string is stored in flen
// (you must pass pointer flen).
char* base64(const void* binaryData, int len, int* flen);

int base64_2(void const *data, int data_len, char *chars, int *chars_len);

int base64_block(base64_block_data_t* input, base64_block_encoded_t* output);

// Convert your base64 string haJIh/+ back to binary data.
// len is the string length and should NOT include the null terminator.
// Final size will be stored in flen
// (you must pass pointer flen).
unsigned char* unbase64(const char* ascii, int len, int* flen);

int unbase64_2(unsigned char const *ascii, int ascii_len, uint8_t *data, int *data_len);

int unbase64_block(base64_block_encoded_t* input, base64_block_data_t* output);

// Checks the integrity of a base64 string to make sure it is
// made up of only characters in the base64 alphabet (array b64)
#define isbase64ValidChr(ch)                               \
  (('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'Z') || \
   ('a' <= ch && ch <= 'z') || ch == '+' ||                \
   ch == '/')  // other 2 valid chars, + ending chrs
// = is NOT considered a valid base64 chr, it's only valid at the end for
// padding

// Tells you if a string is valid base64, which means it's length is
// a multiple of 4, and it contains only valid base64 chrs.
int base64integrity(const char* ascii, int len);

#endif  // NIBBLEANDAHALF_SRC_BASE64_H
