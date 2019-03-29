# source files
TARGET	:= $(shell basename $(PWD))
CCRSC	:= $(wildcard *.c)
COBJS	:= $(CSRCS:.c=.o)
SSRCS	:= $(wildcard *.S)
SOBJS	:= $(SSRCS:.S=.o)
OBJS	:= $(CSRCS) $(SOBJS)

# define the processor here
MCU		:= atmega328p

# define the USB port on your system (this works on Linux)
PORT	:= /dev/ttyACM0
PGMR	:= arduino

# build files
LST	:= $(TARGET).lst

# tools
GCC		:= avr-gcc
OBJDUMP	:= avr-objdump
OBJCOPY	:= avr-objcopy
DUDE	:= avrdude

LFLAGS	:=  -v -D -p $(MCU) -c$(PGMR)
LFLAGS		+= -P$(PORT)
LFLAGS		+= -b115200

CFLAGS	:= -mmcu=$(MCU)

.PHONY all:
all:	$(TARGET).hex $(LST)

# implicit build rules
%.hex:	%.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

%.elf:	$(OBJS)
	$(GCC) -w -Os $(CFLAGS) -o $@ $^ 

%.o:	%.c	config.inc
	$(GCC) -c $(CFLAGS) -o $@ $^

%.o:	%.S config.inc
	$(GCC) -c $(CFLAGS) -o $@ $<

%.lst:	%.elf
	$(OBJDUMP) -C -d $< > $@

# utility targets
.PHONY:	load
load:
	$(DUDE) $(DUDECONF) $(LFLAGS) -Uflash:w:$(TARGET).hex:i

.PHONY:	clean
clean:
	$(RM) *.hex *.lst *.o *.elf
