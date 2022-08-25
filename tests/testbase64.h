//
//  base64test.h
//  NibbleAndAHalf
//
//  Created by William Sherif on 4/17/13.
//  UNIT TESTS ONLY.
//  YOU DO NOT NEED THIS FILE WHEN USING "base64.h"
//
#ifndef NIBBLEANDAHALF_TESTS_TESTBASE64_H
#define NIBBLEANDAHALF_TESTS_TESTBASE64_H

#include <time.h>

#include "Timer.h"

extern int BASE64TESTSHOWDATA;
extern int SHOWTIMING;

// Function for automated testing of base64.h.  Also times.
int testBase64(const void* data, int dataLen);

int testBase64String(const char* str);

void testUnbase64WithBadAscii(void);

void testUnbase64WithBadLength(void);

void automatedTests(void);

// Prints the unb64 array in base64.h
void printUnbase64(void);

#endif  // NIBBLEANDAHALF_TESTS_TESTBASE64_H
