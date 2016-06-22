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
    printf("                  error_code: %d\r", sf->error_code);
    printf("> interrupt: %d\n", sf->interrupt_no);

    printf("                  ebx: %#X\r", sf->ebx);
    printf("> eax: %#X\n", sf->eax);
    printf("                  edx: %#X\r", sf->edx);
    printf("> ecx: %#X\n", sf->ecx);

    printf("                  edi: %#X\r", sf->edi);
    printf("> esi: %#X\n", sf->esi);
    printf("                  esp: %#X\r", sf->esp);
    printf("> ebp: %#X\n", sf->ebp);

    printf("                  eflags: %#X\r", sf->eflags);
    printf("> eip: %#X\n", sf->eip);

    printf("                  ds: %#X\r", sf->ds);
    printf("> cs: %#X\n", sf->cs);
    printf("                  fs: %#X\r", sf->fs);
    printf("> es: %#X\n", sf->es);
    printf("                  gs: %#X\r", sf->gs);
    printf("> ss: %#X\n", sf->ss);

    while(1);
}

