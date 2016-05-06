[org 0x7c00]

mov [BOOT_DISK], dl                             ; remember the boot disk

mov bp, 0x8000                                  ; initialise stack
mov sp, bp

mov bx, HELLO_MSG                               ; print welcome message
call print_str

mov bx, 0x9000                                  ; read disk
mov dh, 5
mov dl, [BOOT_DISK]
call disk_read

mov dx, [0x9000]
call print_hex

mov dx, [0x9000+256]
call print_hex

jmp $

%include "print.asm"
%include "disk.asm"

BOOT_DISK: db 0
HELLO_MSG: db 'Welcome to zbOS!', 13, 10, 0
    
times 510-($-$$) db 0
dw 0xaa55

times 1024 dw 0xdada
times 1024 dw 0xface
