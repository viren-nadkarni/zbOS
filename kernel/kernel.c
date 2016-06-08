#include "scr.h"
#include "kbd.h"
#include "idt.h"
#include "irq.h"
#include "timer.h"
#include "stdio.h"

void kmain() {
    term_init();

    printf("Initialising interrupt handler...\n");
    idt_init();
    irq_init();
    asm volatile ("sti");

    printf("Initialising timer...\n");
    timer_init(100);

    /*
    asm volatile ("xchg %bx, %bx");
    asm volatile ("int $0x5");
    */

    printf("Hello from libc!\n");

    printf("<loop>\n");

    while(1);
}

