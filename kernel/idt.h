#ifndef IDT_H_
#define IDT_H_

#include "def.h"

void idt_init(void);
void idt_setgate(uint8, uint32, uint16, uint8);

#endif
