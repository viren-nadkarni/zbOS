; the global descriptor table
[bits 16]

gdt_start:

gdt_null:                           ; null descriptor
    dd 0x0
    dd 0x0

gdt_code:                           ; code segment descriptor
; base=0x0, limit=0xfffff
; first flags: (present)1 (privilege)00 (descriptor type)1 -> 1001b
; type flags: (code)1 (conforming)0 (readable)1 (accessed)0 -> 1010b
; second flags: (granularity)1 (32bit default)1 (64bit seg)0 (AVL)0 -> 1100b
    
    dw 0xffff                       ; limit (bits 0-15)
    dw 0x0                          ; base (bits 0-15)
    db 0x0                          ; base (bits 16-23)
    db 10011010b                    ; first flags, type flags
    db 11001111b                    ; second flags, limit (bits 16-19)
    db 0x0                          ; base (bits 24-31)

gdt_data:                           ; data segment descriptor
; same as code segment except for the type flags:
; type flags: (code)0 (expand down)0 (writable)1 (accessed)0 -> 0010 b

    dw 0xffff                       ; limit (bits 0-15)
    dw 0x0                          ; base (bits 0-15)
    db 0x0                          ; base (bits 16-23)
    db 10010010b                    ; first flags, type flags
    db 11001111b                    ; second flags, limit (bits 16-19)
    db 0x0                          ; base (bits 24-31)

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1      ; size of GDT
    dd gdt_start                    ; start address of GDT

    CODE_SEG equ gdt_code - gdt_start
    DATA_SEG equ gdt_data - gdt_start

