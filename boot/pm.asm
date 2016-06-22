[bits 16]

pm_switch:
    cli                             ; disable interrupts

    mov eax, cr0                    ; set the protected mode flag
    or eax, 0x0000001
    mov cr0, eax

    jmp CODE_SEG:pm_init            ; clear the cpu pipline with the jump

[bits 32]

pm_init:
    mov ax, DATA_SEG                ; initialise the registers for protected mode
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call pm_begin

