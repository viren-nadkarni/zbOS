#include "isr.h"
#include "stdio.h"

void fault_handler(struct stack_frame *sf) {
     char *exception_message[] = {
        "Divide-by-zero Error",
        "Debug",
        "Non-maskable Interrupt",
        "Breakpoint",
        "Overflow",
        "Bound Range Exceeded",
        "Invalid Opcode",
        "Device Not Available",
        "Double Fault",
        "Coprocessor Segment Overrun",
        "Invalid TSS",
        "Segment Not Preset",
        "Stack-Segment Fault",
        "General Protection Faul",
        "Page Fault",
        "Reserved",
        "x87 Floating-Point Exception",
        "Alignment Check",
        "Machine Check",
        "SIMD Floating-Point Exception",
        "Virtualization Exception",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Security Exception",
        "Reserved",
    };

    if( (sf->interrupt_no) < 32 )
        printf("[!] Exception (%s)\n", exception_message[ sf->interrupt_no ]);
    else
        printf("[!] Exception\n");
    printf("[!] System Halted\n");
    printf("INT=%d ERR=%d\n", sf->interrupt_no, sf->error_code);
    printf("EAX=%08x EBX=%08x ECX=%08x EDX=%08x\n", sf->eax, sf->ebx, sf->ecx, sf->edx);
    printf("ESI=%08x EDI=%08x EBP=%08x ESP=%08x\n", sf->esi, sf->edi, sf->ebp, sf->esp);
    printf("EIP=%08x EFL=%08x\n", sf->eip, sf->eflags);
    printf("CS=%04x DS=%04x\n", sf->cs, sf->ds);
    printf("ES=%04x FS=%04x\n", sf->es, sf->fs);
    printf("SS=%04x GS=%04x\n", sf->ss, sf->gs);

    while(1);
}

