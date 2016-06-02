#include "irq.h"
#include "idt.h"
#include "isr.h"
#include "io.h"

void *irq_routine[16] = { 0 };

void irq_install_handler(int irq, void (*handler)(struct stack_frame *sf)) {
    irq_routine[irq] = handler;
}

void irq_uninstall_handler(int irq) {
    irq_routine[irq] = 0;
}

void irq_remap() {
    /* remap IRQs 0-7 to IDT 32-47 */
    outb(0x20, 0x11);
    outb(0xA0, 0x11);

    outb(0x21, 0x20);
    outb(0xA1, 0x28);

    outb(0x21, 0x04);
    outb(0xA1, 0x02);

    outb(0x21, 0x01);
    outb(0xA1, 0x01);

    outb(0x21, 0x00);
    outb(0xA1, 0x00);
}

void irq_init() {
    irq_remap();

    idt_setgate(32, (unsigned)irq0, 0x08, 0x8E);
    idt_setgate(33, (unsigned)irq1, 0x08, 0x8E);
    idt_setgate(34, (unsigned)irq2, 0x08, 0x8E);
    idt_setgate(35, (unsigned)irq3, 0x08, 0x8E);
    idt_setgate(36, (unsigned)irq4, 0x08, 0x8E);
    idt_setgate(37, (unsigned)irq5, 0x08, 0x8E);
    idt_setgate(38, (unsigned)irq6, 0x08, 0x8E);
    idt_setgate(39, (unsigned)irq7, 0x08, 0x8E);
    idt_setgate(40, (unsigned)irq8, 0x08, 0x8E);
    idt_setgate(41, (unsigned)irq9, 0x08, 0x8E);
    idt_setgate(42, (unsigned)irq10, 0x08, 0x8E);
    idt_setgate(43, (unsigned)irq11, 0x08, 0x8E);
    idt_setgate(44, (unsigned)irq12, 0x08, 0x8E);
    idt_setgate(45, (unsigned)irq13, 0x08, 0x8E);
    idt_setgate(46, (unsigned)irq14, 0x08, 0x8E);
    idt_setgate(47, (unsigned)irq15, 0x08, 0x8E);
}

void irq_handler(struct stack_frame *sf) {
    void (*handler)(struct stack_frame *sf);

    handler = irq_routine[sf->interrupt_no - 32];

    if(handler) {
        handler(sf);
    }

    if(sf->interrupt_no >= 40) {
        outb(0xA0, 0x20);
    }

    /* send an 'End of Interrupt' to the controller */
    outb(0x20, 0x20);
}


