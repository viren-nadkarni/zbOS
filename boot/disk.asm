; BIOS routine to read from disk drive
; expects
;   bx: destination address
;   dl: disk to read (0-indexed)
;   dh: number of sectors to read
;   es: destination offset

disk_read:
    push dx

    mov ah, 0x02                ; BIOS disk read interrupt
    mov al, dh
    mov ch, 0x00                ; cylinder 0
    mov dh, 0x00                ; head 0
    mov cl, 0x02                ; sector 2, the one after boot sector

    int 0x13

    jc disk_error               ; err if carry flag is set

    pop dx
    cmp dh, al
    jne disk_error              ; err if different number of blocks could be read

    ret

disk_error:
    mov bx, DISK_ERROR_MSG
    call print_str
    jmp $

DISK_ERROR_MSG: db 'Error reading disk!', 0

