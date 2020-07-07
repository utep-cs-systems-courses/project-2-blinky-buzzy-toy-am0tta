#include <msp430.h>
#include "../demos/timerLib/libTimer.h"
#include "clocksTimer.h"
#include "../demos/timerLib/sr.h"
#include "switches.h"
#include "led.h"
//#include "sr.h"

int main(){

  configureClocks();
  switch_init();
  led_init();

  or_sr(0x18);        // CPU off, GIE on

}

    
