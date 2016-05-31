#include "isr.h"
#include "scr.h"

char *exception_message[] = {
    "Division by Zero Exception",
    "Debug Exception",
    "Non Maskable Interrupt Exception",
    "Breakpoint Exception",
    "Into Detected Overflow Exception",
    "Out of Bounds Exception",
    "Invalid Opcode Exception",
    "No Coprocessor Exception",
    "Double Fault Exception",
    "Coprocessor Segment Overrun Exception",
    "Bad TSS Exception",
    "Segment Not Preset Exception",
    "Stack Fault Exception",
    "General Protection Faul Exception",
    "Page Fault Exception",
    "Unknown Interrupt Exception",
    "Coprocessor Fault Exception",
    "Alignment Check Exception",
    "Machine Check Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
    "Reserved Exception",
};

void fault_handler(struct stack_frame *sf) {
    term_putstr("\r\n*** Exception. System Halted ***\r\n");
    if( (sf->interrupt_no) < 32 ) {
        term_putstr( exception_message[ sf->interrupt_no ] );
    }
    while(1);
}

