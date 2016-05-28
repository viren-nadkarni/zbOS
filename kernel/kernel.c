#include "scr.h"
#include "kbd.h"
#include "idt.h"

void kmain() {
    term_init();

    term_putstr("Loading interrupt descriptor table...\r\n");
    idt_init();

    term_putstr("<loop>");
    while(1);
}

