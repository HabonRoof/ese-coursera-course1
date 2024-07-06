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
#		build: build executable file name c1m2.out
#		<FILE>.i: precompiled source file in .i extension
#		<FILE>.o: objet file
#		<FILE>.asm: assembly file of source code
#		<FILE>.dep: dependency of source file
#
# Platform Overrides:
#      	PLATFORM = HOST/MSP432
#		
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines, default are host toolchain
CC = gcc
LD = ld
SIZE = size
LDFLAGS = -Wl,-Map=$(OUTPUT).map
CPPFLAGS = $(addprefix -I, $(INCLUDES))
CFLAGS = -D$(PLATFORM) -Wall -g -O0 -std=c99
OUTPUT = c1m2
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.dep)

ifeq ($(PLATFORM), MSP432)
# arm-non-eabi toolchain
# include MSP432 specific header files
	INCLUDES += ../include/CMSIS \
	../include/msp432
# add MSP432 specific source file
	SOURCES += interrupts_msp432p401r_gcc.c \
	startup_msp432p401r_gcc.c \
	system_msp432p401r.c
# change compilet to arm
	CC = arm-none-eabi-gcc
# change linker
	LDFLAGS += -Wl,-T $(LINKER_FILE)
# Add compiler flags
	CFLAGS += -mcpu=$(CPU) \
	-m$(ARCH) -march=armv7e-m \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16 \
	--specs=$(SPECS)
# change size tool
	SIZE = arm-none-eabi-size
else
# native toolchain

endif

# step 1. preprocessor generate .i files
%.i: %.c
	@echo "generating precompiled file"
	$(CC) -E $(CPPFLAGS) $(CFLAGS) $< -o $@

# step 2. compiler compile .i file into .asm files
%.asm: %.c
	@echo "generating assembly file"
	$(CC) -S $(CPPFLAGS) $(CFLAGS) $< -o $@

#step 3. assembler assemble .asm to object .o file
%.o: %.c
	@echo "generating object files without linking"
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

# step 4. compiler will automatically using linker to build executable
# 		  no manual call ld to do this, just generate .out file and its done(?)
$(OUTPUT).out:$(OBJS)
	@echo "linking and generating executable file"
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

# step 5, dependency?
%.dep: %.c
	@echo "generating dependency files"
	$(CC) -MM -c $(CPPFLAGS) $(CFLAGS) $< -o $@

.PHONY:size
size:
	size $(OBJS) $(OUTPUT).out 

.PHONY:compile-all
compile-all: $(SOURCES:.c=.asm)

.PHONY:build
build: $(OUTPUT).out $(DEPS) size

.PHONY:clean
clean:
	rm -f $(OBJS) *.i *.o *.asm *.map *.out *.dep