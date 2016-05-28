[org 0x7c00]
    KERNEL_OFFSET equ 0x1000        ; address where kernel is to be loaded

    mov [BOOT_DISK], dl             ; remember the boot disk

    mov bp, 0x9000                  ; initialise stack
    mov sp, bp

    mov bx, HELLO_MSG
    call print_str

    mov bx, LOAD_KERNEL_MSG
    call print_str
    call load_kernel

    mov bx, LOAD_GDT_MSG
    call print_str
    lgdt [gdt_descriptor]           ; load the gdt

    mov bx, PROT_MODE_MSG
    call print_str
    call pm_switch

    jmp $                           ; hang. this shouldn't happen

load_kernel:
    mov bx, KERNEL_OFFSET
    mov dh, 16
    mov dl, [BOOT_DISK]
    call disk_read

    ret

[bits 32]

pm_begin:
   jmp KERNEL_OFFSET


BOOT_DISK:
    db 0

HELLO_MSG:
    db 'Welcome to zbOS!', 13, 10, 0

LOAD_KERNEL_MSG:
    db 'Loading kernel...', 13, 10, 0

LOAD_GDT_MSG:
    db 'Loading global descriptor table...', 13, 10, 0

PROT_MODE_MSG:
    db 'Switching to protected mode...', 13, 10, 0

%include "print.asm"
%include "disk.asm"
%include "gdt.asm"
%include "pm.asm"
 
times 510-($-$$) db 0
dw 0xaa55

