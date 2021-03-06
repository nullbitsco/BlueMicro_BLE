/*
Copyright 2020 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H
#include "hardware_variants.h"

// Lazy translation: Bit-C --> n!n pins
#define P_D3      6  //0.06
#define P_D2      8  //0.08
#define P_D1      17 //0.17
#define P_D0      26 //0.20
#define P_D4      22 //0.22
#define P_C6      24 //0.24
#define P_D7      32 //1.00
#define P_E6      11 //0.11
#define P_B4      36 //1.04
#define P_B5      38 //1.06

#define P_F4      31 //0.31
#define P_F5      29 //0.29
#define P_F6      2  //0.02
#define P_F7      47 //1.15
#define P_B1      45 //1.13
#define P_B3      43 //1.11
#define P_B2      10 //0.10
#define P_B6      9  //0.09 

/* HARDWARE DEFINITION*/
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16
#define MATRIX_MUX_COLS 4
#define DEBOUNCETIME 2

/*
 * Keyboard Matrix Assignments
 * The nibble uses a demultiplexer for the cols.
 * to free up more IOs for awesomeness!
 * See matrix.c for more details.
*/
#define MATRIX_ROW_PINS { P_B1, P_B3, P_B2, P_B6, P_D4 }
#define MATRIX_COL_MUX_PINS { P_F4, P_F5, P_F6, P_F7 }
#define MATRIX_COL_PINS { }
#define UNUSED_PINS {}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define BATTERY_TYPE BATT_LIPO
#define VBAT_PIN  4
#define VCC_PIN 13
#define VCC_POLARITY_ON 0

#endif
// HARDWARE_CONFIG_H 