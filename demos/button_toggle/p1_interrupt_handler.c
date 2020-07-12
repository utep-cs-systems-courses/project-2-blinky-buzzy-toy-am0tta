#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
  P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
  switch_interrupt_handler();	/* single handler for all switches */

 }
}
/*
void
___interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if(++blink_count == 125){
    state_advance();
    blink_count = 0;
  }
  }*/

