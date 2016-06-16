#ifndef IRQ_H_
#define IRQ_H_

#include "isr.h"

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

void irq_install_handler(int, void (*handler)(struct stack_frame*));
void irq_uninstall_handler(int);
void irq_remap(void);
void irq_init(void);

#endif