#include "isr.h"
#include "stdio.h"

void fault_handler(struct stack_frame *sf) {
     char *exception_message[] = {
        "Division by Zero",
        "Debug",
        "Non Maskable Interrupt",
        "Breakpoint",
        "Into Detected Overflow",
        "Out of Bounds",
        "Invalid Opcode",
        "No Coprocessor",
        "Double Fault",
        "Coprocessor Segment Overrun",
        "Bad TSS",
        "Segment Not Preset",
        "Stack Fault",
        "General Protection Faul",
        "Page Fault",
        "Unknown Interrupt",
        "Coprocessor Fault",
        "Alignment Check",
        "Machine Check",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
    };

    printf("----------------------------------------\n");
    printf("Exception!");
    if( (sf->interrupt_no) < 32 )
        printf(" %s", exception_message[ sf->interrupt_no ]);
    printf("\nSystem Halted\n");
    printf("----------------------------------------\n");

    printf("                error_code: %d\r", sf->error_code);
    printf("interrupt: %d\n", sf->interrupt_no);
    printf("\n");

    printf("                ebx: %X\r", sf->ebx);
    printf("eax: %X\n", sf->eax);
    printf("                edx: %X\r", sf->edx);
    printf("ecx: %X\n", sf->ecx);
    printf("\n");

    printf("                edi: %X\r", sf->edi);
    printf("esi: %X\n", sf->esi);
    printf("                esp: %X\r", sf->esp);
    printf("ebp: %X\n", sf->ebp);
    printf("\n");

    printf("                eflags: %X\r", sf->eflags);
    printf("eip: %X\n", sf->eip);
    printf("\n");

    printf("                ds: %X\r", sf->ds);
    printf("cs: %X\n", sf->cs);
    printf("                fs: %X\r", sf->fs);
    printf("es: %X\n", sf->es);
    printf("                gs: %X\r", sf->gs);
    printf("ss: %X\n", sf->ss);

    printf("----------------------------------------\n");

    while(1);
}

