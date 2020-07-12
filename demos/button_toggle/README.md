# Project 2: Blinky-Buzzy Toy

## Overview
The objective is to use the MSP430 Microcontroller to design a toy, by
utilizing the four switches, the two LED's, and the speaker.

## How to Use the Program:
To compile the program type **make all** and to run it type **make load**. To
clean the repo simply type **make clean**.

* Switch 1 generates sounds that go from a low frequency to a high frequency.
* Switch 2 dims the green LED and brightly illuminates the red LED.
  It also mutes any tones produced by the speaker.
* Switches 3 and 4 produce a different tone.

## Feedback by Teaching Team/ Breakout Groups/ Lab Sessions
1. Play with the demos to see how they behave
2. Migrate the contents of demos' directories to new directories to keep the
orignal code intact.
3. Keep the state machine simple

## Shortcoming(s)
1. My program was not compiling in the project directory. Therefore, I
included it in a directory named **button_toggle** that can be found in the
demos directory.

