#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = MKL25Z128xxx4_flash.ld
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
CC =gcc
LD =arm-none-eabi-ld
LDFLAGS =-T msp432p401r.lds
CPPFLAGS =$(addprefix -I, $(INCLUDES))
CFLAGS =-Wall -Werror -g -O0 -std=c99
OUTPUT =c1m2
OBJS =$(SRCS:.c=.o)

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS += -DHOST
else
	CC = arm-none-eabi-gcc
	CFLAGS += -DMSP432 -mcpu=cortexm4 -mthumb -march-armv7e-m \
	-mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
endif

%.i: %.c
	$(CC) -E $(CPPFLAGS) $(CFLAGS) $< -o $@

.PHONY:all
all: $(OBJS)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

.PHONY:clean
clean:
rm -f $(OBJS) *.i