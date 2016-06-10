#include "timer.h"
#include "irq.h"
#include "def.h"
#include "io.h"

uint32 ticks = 0;

void timer_handler(struct stack_frame *sf) {
    ticks++;
}

void timer_init(uint32 frequency) {
    uint32 time_period = 1193180 / frequency;

    outb(0x43, 0x36);
    outb(0x40, time_period & 0xFF);
    outb(0x40, time_period >> 8);

    irq_install_handler(0, timer_handler);
}

