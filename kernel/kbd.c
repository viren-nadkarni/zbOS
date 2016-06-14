#include "kbd.h"
#include "isr.h"
#include "irq.h"
#include "io.h"
#include "stdio.h"

/* Scancodes for US QWERTY keyboard */
const char us_qwerty[128] = {
    0, 27 /* Esc */, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 8 /* Backspace */,
    9 /* Tab */, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 10 /* Enter */,
    0 /* Ctrl */, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0 /* LShift */, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0, 0 /* Alt */, ' ', 0 /* Caps lock */,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 /* Fn 1-10 */,
    0 /* Num lock */, 0 /* Scroll lock */, 0 /* Home */,
    0 /* Up arrow */, 0 /* Page up */, '-', 0 /* Left arrow */,
    0, 0 /* Right arrow */, '+', 0 /* Down arrow */, 0 /* Page down */,
    0 /* Insert */, 0 /* Delete */, 0, 0, 0,
    0, 0 /* Fn 11-12 */, 0 /* others keys undefined */,
};

void kbd_handler(struct stack_frame *sf) {
    char scancode;

    scancode = inb(0x60);

    if(scancode & 0x80) {
        /* key has been released, indicated by MSB */
        /* TODO: use to implement Shift, Alt, etc. */
    } else {
        /* key has been pressed */
        putchar(us_qwerty[scancode]);
    }
}

void kbd_init() {
    irq_install_handler(1, kbd_handler);
}

