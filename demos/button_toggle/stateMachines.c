#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char toggle_red()/* always toggle! */
  
{

  static char state = 0;
  switch (state) {
  case 0:

    red_on = 1;
    state = 1;
    break;

  case 1:
    red_on = 0;
    state = 0;
    break;

  }

  return 1;/* always changes an led */

}

char toggle_green()/* only toggle green if red is on!  */
  
{

  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;

  }

  return changed;

}

void state_advance()/* alternate between toggling red & green */

{

 


unsigned int switches = p2sw_read();

if(~switches & SW1){

  for(int i = 1200;i<20000/2;i++){

    for(int j = 800;j<2000/2; j++){

      buzzer_set_period(i);

    }

  }

 }

 else if(~switches & SW2){

   buzzer_set_period(100);
   char changed = 0;
  static enum {R=0, G=1} color = G;

  switch (color) {
  case R: changed = toggle_red(); color = G; break;

  case G: changed = toggle_green(); color = R; break;

  }

  led_changed = changed;

  led_update();

 }
 else if(~switches & SW3)

   buzzer_set_period(150);


 else if(~switches & SW4)

   buzzer_set_period(650);
}
