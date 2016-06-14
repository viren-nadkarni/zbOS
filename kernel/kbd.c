#include "kbd.h"
#include "isr.h"
#include "irq.h"
#include "io.h"
#include "def.h"
#include "stdio.h"
#include "stdbool.h"
#include "ctype.h"

/* TODO:
 * - punctuation marks (!@#$%...)
 * - control characters (ctrl-c)
 * - caps/num/scroll lock
 * - function keys?
 * - modular keymaps instead of static definitions?
 */

/* scancodes for US QWERTY */
const uint8 US_QWERTY[128] = {
    0, 27 /* Esc */, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 8 /* Backspace */,
    9 /* Tab */, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 10 /* Enter */,
    0 /* Ctrl */, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0 /* Shift */, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0, 0 /* Alt */, ' ', 0 /* Caps lock */,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 /* Fn 1-10 */,
    0 /* Num lock */, 0 /* Scroll lock */, 0 /* Home */,
    0 /* Up arrow */, 0 /* Page up */, '-', 0 /* Left arrow */,
    0, 0 /* Right arrow */, '+', 0 /* Down arrow */, 0 /* Page down */,
    0 /* Insert */, 0 /* Delete */, 0, 0, 0,
    0, 0 /* Fn 11-12 */, 0 /* other keys left undefined */,
};

#define SHIFT_HOLD      0x2A
#define SHIFT_RELEASE   0xAA

#define ALT_HOLD        0x38
#define ALT_RELEASE     0xb8
#define RALT_MOD        0xe0

#define CTRL_HOLD       0x1d
#define CTRL_RELEASE    0x9d
#define RCTRL_MOD       0xe0

static bool shift_pressed=false, alt_pressed=false, ctrl_pressed=false;

void kbd_handler(struct stack_frame *sf) {
    uint8 scancode, key;

    scancode = inb(0x60);

    if(scancode & 0x80) {
        /* key has been released, indicated by MSB */
        /* TODO: differentiate between Left and Right modifier keys */
        if(scancode == SHIFT_RELEASE)
            shift_pressed = false;

        if(scancode == ALT_RELEASE)
            alt_pressed = false;

        if(scancode == CTRL_RELEASE)
            ctrl_pressed = false;

   } else {
        /* key has been pressed */
        if(scancode == SHIFT_HOLD)
            shift_pressed = true;

        if(scancode == ALT_HOLD)
            alt_pressed = true;

        if(scancode == CTRL_HOLD)
            ctrl_pressed = true;

        key = US_QWERTY[scancode];

        if(isalpha(key))
            if(shift_pressed)
                putchar(toupper(key));
        else
            putchar(key);
    }
}

void kbd_init() {
    irq_install_handler(1, kbd_handler);
}

