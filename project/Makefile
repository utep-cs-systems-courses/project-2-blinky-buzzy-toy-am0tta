# makefile configuration
COMMON_OBJECTS  =

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf #libTimer.a

#libTimer.a: clocksTimer.o sr.o
#	$(AR) crs $@ $^

#additional rules for files
button.elf: ${COMMON_OBJECTS} led.o main.o switches.o p1_interrupt_handler.o sr.o clocksTimer.o

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

sr.o: sr.h

clean:
	rm -f *.o *.elf
