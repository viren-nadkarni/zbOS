#include "idt.h"
#include "isr.h"

extern void idt_load(void);

struct idt_entry {
    uint16 base_low;            /* lower 16 bits of the jump address */
    uint16 selector;            /* kernel segment selector */
    uint8 padding;              /* always 0 */
    uint8 flags;                /* flags */
    uint16 base_high;           /* upper 16 bits of the jump address */
} __attribute__((packed));

struct idt_ptr {
    uint16 length;
    uint32 base;                /* base address of idt_entry_t array */
} __attribute__((packed));

struct idt_entry idt[256];
struct idt_ptr idtp;

void idt_init() {
    idtp.length = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint32)&idt;

    /* TEMP HACK: use memset instead to clear idt memory */
    uint8 *ptr = (uint8*)&idt;
    for(uint16 i=0; i<=idtp.length; ++i, ++ptr) {
        *ptr = 0;
    }

    /* register interrupt service routines */
    idt_setgate(0, (unsigned)isr0, 0x08, 0x8E);
    idt_setgate(1, (unsigned)isr1, 0x08, 0x8E);
    idt_setgate(2, (unsigned)isr2, 0x08, 0x8E);
    idt_setgate(3, (unsigned)isr3, 0x08, 0x8E);
    idt_setgate(4, (unsigned)isr4, 0x08, 0x8E);
    idt_setgate(5, (unsigned)isr5, 0x08, 0x8E);
    idt_setgate(6, (unsigned)isr6, 0x08, 0x8E);
    idt_setgate(7, (unsigned)isr7, 0x08, 0x8E);
    idt_setgate(8, (unsigned)isr8, 0x08, 0x8E);
    idt_setgate(9, (unsigned)isr9, 0x08, 0x8E);
    idt_setgate(10, (unsigned)isr10, 0x08, 0x8E);
    idt_setgate(11, (unsigned)isr11, 0x08, 0x8E);
    idt_setgate(12, (unsigned)isr12, 0x08, 0x8E);
    idt_setgate(13, (unsigned)isr13, 0x08, 0x8E);
    idt_setgate(14, (unsigned)isr14, 0x08, 0x8E);
    idt_setgate(15, (unsigned)isr15, 0x08, 0x8E);
    idt_setgate(16, (unsigned)isr16, 0x08, 0x8E);
    idt_setgate(17, (unsigned)isr17, 0x08, 0x8E);
    idt_setgate(18, (unsigned)isr18, 0x08, 0x8E);
    idt_setgate(19, (unsigned)isr19, 0x08, 0x8E);
    idt_setgate(20, (unsigned)isr20, 0x08, 0x8E);
    idt_setgate(21, (unsigned)isr21, 0x08, 0x8E);
    idt_setgate(22, (unsigned)isr22, 0x08, 0x8E);
    idt_setgate(23, (unsigned)isr23, 0x08, 0x8E);
    idt_setgate(24, (unsigned)isr24, 0x08, 0x8E);
    idt_setgate(25, (unsigned)isr25, 0x08, 0x8E);
    idt_setgate(26, (unsigned)isr26, 0x08, 0x8E);
    idt_setgate(27, (unsigned)isr27, 0x08, 0x8E);
    idt_setgate(28, (unsigned)isr28, 0x08, 0x8E);
    idt_setgate(29, (unsigned)isr29, 0x08, 0x8E);
    idt_setgate(30, (unsigned)isr30, 0x08, 0x8E);
    idt_setgate(31, (unsigned)isr31, 0x08, 0x8E);

    /* load the idt on to cpu */
    idt_load();
}

void idt_setgate(uint8 number, uint32 base, uint16 selector, uint8 flags) {
    idt[number].base_low = base & 0xFFFF;
    idt[number].selector = selector;
    idt[number].padding = 0;
    idt[number].flags = flags;
    idt[number].base_high = (base >> 16) & 0xFFFF;
}

