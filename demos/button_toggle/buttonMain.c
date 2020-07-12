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
  p2sw_init(15); //15

  // (p2sw_read());
  led_init();
  //buzzer_set_period(2000);

  enableWDTInterrupts();
  unsigned int switches = p2sw_read();

    if(~switches & SW1){                   //plays a looping tone
      for(int i = 1200;i<20000/2;i++){
	for(int j = 800;j<2000/2; j++){
	  buzzer_set_period(i);
	}
      }
    }
    else if(~switches & SW2){
      buzzer_set_period(100);
    
    }
  
    else if(~switches & SW3)
      buzzer_set_period(150);
  
    else if(~switches & SW4)
      buzzer_set_period(650);
   
    or_sr(0x18);  // CPU off, GIE on
    
}
