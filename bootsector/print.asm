; address of str expected in bx
print_str:
    pusha                   ; push registers to stack
    mov ah, 0x0e            ; write character in tty mode

__loop:
    mov dx, [bx]            ; copy byte to print
    mov al, dl

    cmp al, 0               ; check for end of string
    je __loop_esc

    int 0x10                ; call interrupt

    add bx, 1               ; next byte
    jmp __loop

__loop_esc:
    popa                    ; pop registers and return
    ret

