[org 0x7c00]

mov bx, HELLO_MSG
call print_str

mov bx, GOODBYE_MSG
call print_str
call print_str
call print_str
jmp $

%include "print.asm"

HELLO_MSG:
    db 'Hello world!', 13, 10, 0
    
GOODBYE_MSG:
    db 'Goodbye!', 13, 10, 0

times 510 -($-$$) db 0
dw 0xaa55
