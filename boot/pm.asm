[bits 16]

pm_switch:
    cli                             ; disable interrupts
    lgdt [gdt_descriptor]           ; load the gdt

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

    mov ebp, 0x9000
    mov esp, ebp

    call pm_begin

pm_begin:
    ; do something
    jmp $
