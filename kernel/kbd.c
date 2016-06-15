#include "kbd.h"
#include "isr.h"
#include "irq.h"
#include "io.h"
#include "def.h"
#include "stdio.h"
#include "stdbool.h"
#include "ctype.h"

/* TODO:
 * - differentiate between left & right modifers (right modifiers currently don't work)
 * - control characters (ctrl-c)
 * - function keys?
 * - modular keymaps instead of static definitions?
 */

/* scancodes for US QWERTY */
const uint8 US_QWERTY_lower[128] = {
    0, 27 /* Esc */, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 8 /* Backspace */,
    9 /* Tab */, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 10 /* Enter */,
    0 /* Ctrl */, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0 /* Shift */, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0, '*', 0 /* Alt */, ' ', 0 /* Caps lock */,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 /* Fn 1-10 */,
    0 /* Num lock */, 0 /* Scroll lock */, 0 /* Home */,
    0 /* Up arrow */, 0 /* Page up */, '-', 0 /* Left arrow */,
    0, 0 /* Right arrow */, '+', 0 /* Down arrow */, 0 /* Page down */,
    0 /* Insert */, 0 /* Delete */, 0, 0, 0,
    0, 0 /* Fn 11-12 */, 0 /* other keys left undefined */,
};

const uint8 US_QWERTY_upper[128] = {
    0, 27 /* Esc */, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', 8 /* Backspace */,
    9 /* Tab */, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', 10 /* Enter */,
    0 /* Ctrl */, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~',
    0 /* Shift */, '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
    0, '*', 0 /* Alt */, ' ', 0 /* Caps lock */,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 /* Fn 1-10 */,
    0 /* Num lock */, 0 /* Scroll lock */, 0 /* Home */,
    0 /* Up arrow */, 0 /* Page up */, '-', 0 /* Left arrow */,
    0, 0 /* Right arrow */, '+', 0 /* Down arrow */, 0 /* Page down */,
    0 /* Insert */, 0 /* Delete */, 0, 0, 0,
    0, 0 /* Fn 11-12 */, 0 /* other keys left undefined */,
};

#define SHIFT_HOLD          0x2A
#define SHIFT_RELEASE       0xAA

#define ALT_HOLD            0x38
#define ALT_RELEASE         0xB8
#define RALT_MOD            0xE0

#define CTRL_HOLD           0x1D
#define CTRL_RELEASE        0x9D
#define RCTRL_MOD           0xE0

#define CAPS_LOCK           0x3A
#define NUM_LOCK            0x45
#define SCROLL_LOCK         0x46

#define CAPS_LOCK_LIGHT     0x04
#define NUM_LOCK_LIGHT      0x02
#define SCROLL_LOCK_LIGHT   0x01

static bool shift_pressed, alt_pressed, ctrl_pressed, caps_lock, num_lock, scroll_lock;

void kbd_handler(struct stack_frame *sf) {
    uint8 scancode;

    scancode = inb(0x60);

    if(scancode & 0x80) {
        /* key has been released, indicated by MSB */
        if(scancode == SHIFT_RELEASE)
            shift_pressed = false;

        if(scancode == ALT_RELEASE)
            alt_pressed = false;

        if(scancode == CTRL_RELEASE)
            ctrl_pressed = false;

    } else {
        /* key has been pressed */
        switch(scancode) {
            case SHIFT_HOLD:
                shift_pressed = true;
                break;
            case ALT_HOLD:
                alt_pressed = true;
                break;
            case CTRL_HOLD:
                ctrl_pressed = true;
                break;
            case CAPS_LOCK:
                caps_lock = !caps_lock;
                kbd_switchled(CAPS_LOCK_LIGHT);
                break;
            case NUM_LOCK:
                num_lock = !num_lock;
                kbd_switchled(NUM_LOCK_LIGHT);
                break;
            case SCROLL_LOCK:
                scroll_lock = !scroll_lock;
                kbd_switchled(SCROLL_LOCK_LIGHT);
                break;
        }

        kbd_print(scancode);
    }
}

void kbd_print(uint8 scancode) {
    uint8 c = shift_pressed ? US_QWERTY_upper[scancode] : US_QWERTY_lower[scancode];

    if(caps_lock && isalpha(c)) {
        if(isupper(c))
            putchar(tolower(c));
        else
            putchar(toupper(c));
    } else {
        putchar(c);
    }
}

void kbd_switchled(uint8 xor_status_byte) {
    static uint8 led_status;
    led_status ^= xor_status_byte;

    /* wait if keyboard controller is busy */
    while(true)
        if( !(inb(0x64) & 0x2) )
            break;

    outb(0x60, 0xED);
    outb(0x60, led_status);
}

void kbd_init() {
    irq_install_handler(1, kbd_handler);

    shift_pressed = false;
    alt_pressed = false;
    ctrl_pressed = false;

    caps_lock = false;
    num_lock = false;
    scroll_lock = false;
}

