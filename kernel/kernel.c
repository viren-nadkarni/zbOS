#include "scr.h"
#include "kbd.h"
#include "idt.h"
#include "irq.h"
#include "timer.h"
#include "stdio.h"

void kmain() {
    term_init();

    printf("Initialising interrupts...\n");
    idt_init();
    irq_init();
    asm volatile ("sti");

    printf("Initialising timer...\n");
    timer_init(100);

    /*
    asm volatile ("xchg %bx, %bx");
    */

    printf("<loop>\n");

    while(1);
}

