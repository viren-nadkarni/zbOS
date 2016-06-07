#include "timer.h"
#include "irq.h"
#include "scr.h"
#include "def.h"
#include "io.h"

uint32 timer_ticks = 0;

void timer_handler(struct stack_frame *sf) {
    timer_ticks++;

    if(timer_ticks % 18 == 0) {
        term_putstr("<second tick>\r\n");
    }
}

void timer_init(uint16 frequency) {
    uint16 time_period = 1193180 / frequency;

    outb(0x43, 0x36);
    outb(0x40, time_period & 0xFF);
    outb(0x40, time_period >> 8);

    irq_install_handler(0, timer_handler);
}

