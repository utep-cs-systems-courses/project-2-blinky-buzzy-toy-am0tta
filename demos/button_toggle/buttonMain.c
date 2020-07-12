#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

//#define GREEN_LED BIT6
//#define RED_LED BIT1
void main(void) 
{  
  configureClocks();
  switch_init();
  buzzer_init();
  p2sw_init(15);

  (p2sw_read());
  led_init();
  enableWDTInterrupts();
  
  or_sr(0x18);  // CPU off, GIE on
    
}
