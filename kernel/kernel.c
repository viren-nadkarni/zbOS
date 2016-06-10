#include "scr.h"
#include "kbd.h"
#include "idt.h"
#include "irq.h"
#include "timer.h"
#include "stdio.h"

void kmain() {
    term_init();

    printf("Initialising interrupts...\n");
    /* install interrupt descriptor table */
    idt_init();
    /* configure interrupt requests */
    irq_init();
    /* enable interrupts */
    asm volatile ("sti");

    printf("Initialising timer...\n");
    /* tell the PIT to interrupt 100 times per second */
    timer_init(100);

    /*
    asm volatile ("xchg %bx, %bx");
    */

    printf("<loop>\n");

    while(1);
}

