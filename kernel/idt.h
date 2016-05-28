#ifndef IDT_H_
#define IDT_H_

#include "def.h"

struct idt_entry {
    uint16 base_low;            /* lower 16 bits of the jump address */
    uint16 selector;            /* kernel segment selector */
    uint8 padding;              /* always 0 */
    uint8 flags;                /* flags */
    uint16 base_high;           /* upper 16 bits of the jump address */
} __attribute__((packed));

struct idt_ptr {
    uint16 length;
    void* base;                /* base address of idt_entry_t array */
} __attribute__((packed));

void idt_init();
void idt_setgate(uint8, uint32, uint16, uint8);

#endif
