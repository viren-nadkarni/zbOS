#include "scr.h"
#include "kbd.h"
#include "idt.h"
#include "irq.h"
#include "timer.h"

void kmain() {
    term_init();

    term_putstr("Initialising interrupt handler...\r\n");
    idt_init();
    irq_init();
    asm volatile ("sti");

    term_putstr("Initialising timer...\r\n");
    timer_init(100);

    /*
    asm volatile ("xchg %bx, %bx");
    asm volatile ("int $0x5");
    */

    term_putstr("<loop>");
    while(1);
}

