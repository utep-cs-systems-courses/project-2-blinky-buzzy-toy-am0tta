#include <msp430.h>
#include "switches.h"
#include "led.h"

static unsigned char switch_mask;
static unsigned char switches_last_reported;
static unsigned char switches_current;

char switch_state_down, switch_state_changed; /* effectively boolean */
static void
switch_update_interrupt_sense()
{

  switches_current = P2IN & switch_mask;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (switches_current);  /* if switch up, sense down */
  P2IES &= (switches_current | ~switch_mask); /* if switch down, sense up */

}

void
p2sw_init(unsigned char mask)
{
  switch_mask = mask;
  P2REN |= mask;    /* enables resistors for switches */
  P2IE = mask;      /* enable interrupts from switches */
  P2OUT |= mask;    /* pull-ups for switches */
  P2DIR &= ~mask;   /* set switches' bits for input */

  switch_update_interrupt_sense();

}

/* Returns a word where:
 * the high-order byte is the buttons that have changed,
 * the low-order byte is the current state of the buttons
 */

unsigned int
p2sw_read() {
  unsigned int sw_changed = switches_current ^ switches_last_reported;
  switches_last_reported = switches_current;
  return switches_current | (sw_changed << 8);

}

/* Switch on P2 (S1) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & switch_mask) {  /* did a button cause this interrupt? */
    P2IFG &= ~switch_mask;/* clear pending sw interrupts */
    switch_update_interrupt_sense();

  }
}
static char 
switch_update_interrupt_sense1()
{
char p1val = P1IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val; 
  }
void 
switch_init()			/* setup switch */
{  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense1();
  led_update();
}

//char toggle_state = 1;
void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense1();
  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_changed = 1;
  led_update();
  // *char p1val = switch_update_interrupt_sense1();
  //switch (toggle_state){

    //case 1:                     // led off button up
    //if(!(p1val & SW1))       // button is now down
      // toggle_state = 2;      // new state = led on button down
    //break;
    //case 2:

    // case 3:
    //case 4:*/

}
