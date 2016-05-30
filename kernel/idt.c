#include "idt.h"

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

struct idt_entry idt[256];
struct idt_ptr idtp;

void idt_init() {
    idtp.length = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = &idt;

    /* TEMP HACK: use memset instead to clear idt memory */
    uint8 *ptr = (uint8*)&idt;
    for(uint16 i=0; i<idtp.length; ++i, ++ptr) {
        *ptr = 0;
    }

    /* TODO: add interrupt service routines below */

    /* load the idt on to cpu */
    asm volatile ("lidt %0" : : "m"(idtp) );
}

void idt_setgate(uint8 number, uint32 base, uint16 selector, uint8 flags) {
    idt[number].base_low = base & 0x00FF;
    idt[number].selector = selector;
    idt[number].padding = 0;
    idt[number].flags = flags;
    idt[number].base_high = (base >> 8) & 0x00FF;
}

