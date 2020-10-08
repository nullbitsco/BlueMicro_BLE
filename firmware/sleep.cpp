/*
Copyright 2018-2020 <Pierre Constantineau>

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
#include "sleep.h"
#include "LedRGB.h"
#include "matrix.h"
/**************************************************************************************************************************/
// Prepare sense pins for waking up from complete shutdown
/**************************************************************************************************************************/
void setupWakeUp() {
  select_col(15); //Uppermost right pin is the wakeup pin.

  pinMode(rows[0], INPUT_PULLUP_SENSE);

  //sets READ IN gpios (any gpio that is an INPUT in the matrix)
  for(uint8_t row_index = 1; row_index < MATRIX_ROWS; row_index++) {
    pinMode(rows[row_index], INPUT);  // Set the rest of the pins to input, no PU
  }

  #if VCC_ENABLE_GPIO == 1 
  switchVCC(false); // turn off VCC when going to sleep. This isn't an optional thing...
  #endif
}

/**************************************************************************************************************************/
void gotoSleep(unsigned long timesincelastkeypress, bool connected)
{
  // shutdown when unconnected and no keypresses for SLEEPING_DELAY ms
  if ((timesincelastkeypress >= SLEEPING_DELAY) && (!connected))
  {
    LOG_LV2("SLEEP","Not Connected Sleep %i", timesincelastkeypress);
    pinMode(15, INPUT); //turn LED off

    #if WS2812B_LED_ON == 1 
    suspendRGB();
    #endif
    setupWakeUp();
    delay(1000);
    sd_power_system_off();
  } 

  // shutdown when unconnected and no keypresses for SLEEPING_DELAY_CONNECTED ms
  if ((timesincelastkeypress >= SLEEPING_DELAY_CONNECTED) && (connected))
  {
    pinMode(15, INPUT); //turn LED off

    LOG_LV2("SLEEP","Connected Sleep %i", timesincelastkeypress);
    #if WS2812B_LED_ON == 1 
    suspendRGB();
    #endif
    setupWakeUp();
    sd_power_system_off();
  } 
}
