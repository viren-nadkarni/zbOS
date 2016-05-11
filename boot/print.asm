; Routines to handle printing to screen

; Print a NULL terminated string
; Address of string to be printed is expected in bx
print_str:
    pusha                   ; push registers to stack
    mov ah, 0x0e            ; write character in tty mode

_loop_str:
    mov dx, [bx]            ; copy byte to print
    mov al, dl

    cmp al, 0               ; check for end of string
    je _endloop_str

    int 0x10                ; call interrupt

    add bx, 1               ; next byte
    jmp _loop_str

_endloop_str:
    popa                    ; pop registers and return
    ret


; Print an arbitrary 16-bit word as hex
; Data to printed is expected in dx
print_hex:
    pusha

    mov si, HEX_MAP         ; initialise hex map address
    mov di, HEX_OUT+2       ; initialise destination address

    mov bx, dx              ; first character
    shr bx, 12
    mov al, [si+bx]
    mov [di], al

    mov bx, dx              ; second character
    shr bx, 8
    and bx, 0x0f
    mov al, [si+bx]
    mov [di+1], al

    mov bx, dx              ; third character
    shr bx, 4
    and bx, 0x0f
    mov al, [si+bx]
    mov [di+2], al

    mov bx, dx              ; fourth character
    and bx, 0x0f
    mov al, [si+bx]
    mov [di+3], al

    mov bx, HEX_OUT         ; print
    call print_str

    popa
    ret

HEX_MAP:
    db '0123456789ABCDEF'
HEX_OUT:
    db '0x????', 0


; Print in 32bit protected mode
; Address of string to be printed is expected in ebx
[bits 32]
print_pm_str:
    pusha
    mov edx, 0xb8000        ; video memory address

_loop_pm_str:
    mov al, [ebx]           ; char
    mov ah, 0x0f            ; char property - white on black background

    cmp al, 0
    je _endloop_pm_str
    
    mov [edx], ax           ; store the char at current cell
    add ebx, 1              ; next char
    add edx, 2              ; next cell

    jmp _loop_pm_str

_endloop_pm_str:
    popa
    ret
