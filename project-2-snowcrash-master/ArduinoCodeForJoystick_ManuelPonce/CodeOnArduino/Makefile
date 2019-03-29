# source files
TARGET	:= $(shell basename $(PWD))
CSRCS	:= $(wildcard arduino/*.c)
CXXSRCS	:= $(wildcard arduino/*.cpp)

CXXOBJS	:= $(CXXSRCS:.cpp=.o)
COBJS	:= $(CSRCS:.c=.o)
SSRCS	:= $(wildcard *.S)
SOBJS	:= $(SSRCS:.S=.o)
OBJS	:= arduinoCode.o $(COBJS) $(SOBJS) $(CXXOBJS)

LST	:= $(TARGET).lst

# define the processor here
MCU		:= atmega328p
FREQ	:= 16000000L

# define the USB port on your system (this works on Linux)
PORT	:= /dev/ttyACM0
PGMR	:= arduino

# tools
GCC		:= avr-gcc
GXX		:= avr-g++
OBJDUMP	:= avr-objdump
OBJCOPY	:= avr-objcopy
DUDE	:= avrdude

UFLAGS	:=  -v -D -p$(MCU) -c$(PGMR)
UFLAGS		+= -P$(PORT)
UFLAGS		+= -b115200

CFLAGS	:=  -Os -mmcu=$(MCU)
CFLAGS		+= -DF_CPU=$(FREQ)
CFLAGS  +=  -Wall -Iarduino

LFLAGS	:= -mmcu=$(MCU)
#LFLAGS	+= -nostartfiles
LFLAGS  += -Wl,--gc-sections -lm

.PHONY all:
all:	$(TARGET).hex $(LST)

# implicit build rules
%.hex:	%.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

%.elf:	$(OBJS)
	$(GCC) $(LFLAGS) -o $@ $^ 

%.o:	%.cpp
	$(GXX) -c $(CFLAGS) -o $@ $^

%.o:	%.c
	$(GCC) -c $(CFLAGS) -o $@ $<

%.o:	%.S
	$(GCC) -c $(CFLAGS) -o $@ $<

%.lst:	%.elf
	$(OBJDUMP) -C -d $< > $@

# utility targets
.PHONY:	load
load:
	$(DUDE) $(DUDECONF) $(UFLAGS) -Uflash:w:$(TARGET).hex:i

.PHONY:	clean
clean:
	$(RM) *.hex *.lst *.o *.elf
