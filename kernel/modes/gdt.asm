global load_gdt

gdt_start:

gdt_null:
	dd 0x0
	dd 0x0

gdt_code:
	dw 0xffff
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0

gdt_data:
	dw 0xffff
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0

gdt_end:

gdt_descriptor:
	dw gdt_end - gdt_start - 1
	dd gdt_start

%define CODE_SEGMENT gdt_code - gdt_start
%define DATA_SEGMENT gdt_data - gdt_start

load_gdt:
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 0x1
	mov cr0, eax
	ret
