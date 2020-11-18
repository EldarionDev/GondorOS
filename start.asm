section .text

extern init
extern load_gdt

%define MB_MAGIC 0x1badb002
%define MB_FLAGS 0x0
%define MB_CHECKSUM -(MB_MAGIC + MB_FLAGS)

align 4
dd  MB_MAGIC
dd  MB_FLAGS
dd  MB_CHECKSUM

global _start
_start:
    mov [kernel_stack], esp
    call init
    call load_gdt

    _stop:
        cli
        hlt
        jmp _stop

section .bss
resb 8192
kernel_stack:
