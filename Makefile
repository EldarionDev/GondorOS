SRCS = $(shell find -name '*.c' && find -name '*.asm')
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CC = gcc
LD = ld
ASSEMBLER=nasm
RUN_EMULATOR=qemu-system-x86_64
DEBUG_EMULATOR=bochs

ASFLAGS = -m32
CFLAGS = -m32 -Wall -g -fno-stack-protector -nostdinc
LDFLAGS = -melf_i386 -Ttext=0x100000

gondor_os: $(OBJS)
		$(LD) $(LDFLAGS) -o $@ $^
		cp gondor_os iso/boot/
		grub-mkrescue iso -o gondor_os.iso

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $^

%.o: %.asm
		$(ASSEMBLER) -f elf $^ -o $@	

run: 
		$(RUN_EMULATOR) -kernel gondor_os

debug:
		$(DEBUG_EMULATOR)

clean:
		rm $(OBJS)
		rm iso/boot/gondor_os
		rm gondor_os.iso
		rm gondor_os

.PHONY: clean
