SRCS = $(shell find -name '*.c' && find -name '*.asm')
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CC = gcc
LD = ld
ASSEMBLER=nasm

ASFLAGS = -m32
CFLAGS = -m32 -Wall -g -fno-stack-protector -nostdinc
LDFLAGS = -melf_i386 -Ttext=0x100000

kernel: $(OBJS)
		$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $^

%.o: %.asm
		$(ASSEMBLER) -f elf $^ -o $@	

clean:
		rm $(OBJS)

.PHONY: clean
