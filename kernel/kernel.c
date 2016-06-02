#include "scr.h"
#include "kbd.h"
#include "idt.h"
#include "irq.h"

void kmain() {
    term_init();

    term_putstr("Loading interrupt descriptor table...\r\n");
    idt_init();

    term_putstr("Initialising interrupt requests...\r\n");
    irq_init();

    /*
    asm volatile ("xchg %bx, %bx");
    asm volatile ("int $0x5");
    */
    asm volatile ("sti");

    term_putstr("<loop>");
    while(1);
}

