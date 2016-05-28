#include "def.h"
#include "idt.h"

struct idt_entry idt[256];
struct idt_ptr idtp;

void idt_init() {
    idtp.length = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = &idt;

    /* TODO: clear idt memory */

    /* TODO: add interrupt service routines below */

    /* load the idt on to cpu */
    asm volatile ("lidt %0" : : "m"(idtp) );
}

void idt_setgate(uint8 number, uint32 base, uint16 selector, uint8 flags) {
    /* TODO */
    return;
}
