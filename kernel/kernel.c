#include "scr.h"
#include "kbd.h"
#include "idt.h"
#include "irq.h"
#include "timer.h"
#include "paging.h"

#include "stdio.h"

void kmain() {
    term_init();

    /* install interrupt descriptor table */
    printf("Initialising interrupts...\n");
    idt_init();
    irq_init();
    asm volatile ("sti"); /* enable interrupts */

    printf("Initialising timer...\n");
    timer_init(100); /* tell the PIT to interrupt 100 times per second */

    printf("Initialising keyboard...\n");
    kbd_init(); /* register keyboard IRQ */

    /*
    asm volatile ("xchg %bx, %bx");
    */

    printf("Enabling paging...\n");
    paging_init();

    uint32 *ptr = (uint32*) 0xA0000000;
    uint32 page_fault = *ptr;

    printf("...\n");

    while(1);
}

