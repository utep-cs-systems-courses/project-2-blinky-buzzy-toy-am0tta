#ifndef switches_included
#define switches_included

//#define SW1 BIT3		/* switch1 is p1.3 */

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
//#define SWITCHES SW1		/* only 1 switch on this board */

#define SWITCHES (SW1 | SW2 | SW3 | SW4)

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */
extern char state;

unsigned int p2sw_read();
void p2sw_init(unsigned char mask);

#endif // included
