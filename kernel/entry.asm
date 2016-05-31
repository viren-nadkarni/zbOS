[bits 32]
[extern kmain]
    call kmain
    jmp $               ; this should happen when returning from kernel main
                        ; shutdown?

; interrupt service routine stub
[extern fault_handler]
isr_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    
    mov ax, 0x10        ; load the kernel data segment descriptor
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov eax, esp        ; push stack
    push eax

    mov eax, fault_handler
    call eax            ; preserve eip while calling

    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa

    add esp, 8          ; clean pushed error code and isr number
    iret                ; pop cs, eip, eflags, ss, esp

; interrupt service routines
global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

; interrupt 0: division by zero exception
isr0:
    cli
    push byte 0
    push byte 0
    jmp isr_common_stub

; interrupt 1: debug
isr1:
    cli
    push byte 0
    push byte 1
    jmp isr_common_stub

; interrupt 2: non maskable interrupt
isr2:
    cli
    push byte 0
    push byte 2
    jmp isr_common_stub

; interrupt 3: breakpoint
isr3:
    cli
    push byte 0
    push byte 3
    jmp isr_common_stub

; interrupt 4: into detected overflow
isr4:
    cli
    push byte 0
    push byte 4
    jmp isr_common_stub

; interrupt 5: out of bounds
isr5:
    cli
    push byte 0
    push byte 5
    jmp isr_common_stub

; interrupt 6: invalid opcode
isr6:
    cli
    push byte 0
    push byte 6
    jmp isr_common_stub

; interrupt 7: no coprocessor
isr7:
    cli
    push byte 0
    push byte 7
    jmp isr_common_stub

; interrupt 8: double fault
isr8:
    cli
    push byte 8
    jmp isr_common_stub

; interrupt 9: coprocessor segment overrun
isr9:
    cli
    push byte 0
    push byte 9
    jmp isr_common_stub

; interrupt 10: bad tss
isr10:
    cli
    push byte 10
    jmp isr_common_stub

; interrupt 11: segment not present
isr11:
    cli
    push byte 11
    jmp isr_common_stub

; interrupt 12: stack fault
isr12:
    cli
    push byte 12
    jmp isr_common_stub

; interrupt 13: general protection fault
isr13:
    cli
    push byte 13
    jmp isr_common_stub

; interrupt 14: page fault
isr14:
    cli
    push byte 14
    jmp isr_common_stub

; interrupt 15: unknown interrupt
isr15:
    cli
    push byte 0
    push byte 15
    jmp isr_common_stub

; interrupt 16: coprocessor fault
isr16:
    cli
    push byte 0
    push byte 16
    jmp isr_common_stub

; interrupt 17: alignment check
isr17:
    cli
    push byte 0
    push byte 17
    jmp isr_common_stub

; interrupt 18: machine check
isr18:
    cli
    push byte 0
    push byte 18
    jmp isr_common_stub

; interrupt 19-31: reserved
isr19:
    cli
    push byte 0
    push byte 19
    jmp isr_common_stub

isr20:
    cli
    push byte 0
    push byte 20
    jmp isr_common_stub

isr21:
    cli
    push byte 0
    push byte 21
    jmp isr_common_stub

isr22:
    cli
    push byte 0
    push byte 22
    jmp isr_common_stub

isr23:
    cli
    push byte 0
    push byte 23
    jmp isr_common_stub

isr24:
    cli
    push byte 0
    push byte 24
    jmp isr_common_stub

isr25:
    cli
    push byte 0
    push byte 25
    jmp isr_common_stub

isr26:
    cli
    push byte 0
    push byte 26
    jmp isr_common_stub

isr27:
    cli
    push byte 0
    push byte 27
    jmp isr_common_stub

isr28:
    cli
    push byte 0
    push byte 28
    jmp isr_common_stub

isr29:
    cli
    push byte 0
    push byte 29
    jmp isr_common_stub

isr30:
    cli
    push byte 0
    push byte 30
    jmp isr_common_stub

isr31:
    cli
    push byte 0
    push byte 31
    jmp isr_common_stub

