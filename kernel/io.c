#include "def.h"
#include "io.h"

void outb(uint16 port, uint8 value) {
    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

uint8 inb(uint16 port) {
    uint8 value;
    asm volatile ("inb %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

