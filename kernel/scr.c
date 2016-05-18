#include "vga.h"
#include "scr.h"
#include "io.h"


uint16 cursor_offset = 0;

void term_init() {
    term_clear();

    /* set the cursor to the first line */
    term_setcursor(0, 0);
}


void term_clear() {
    volatile uint8* cell = (volatile uint8*) VGA_MEMORY;

    for(int i = 0; i < VGA_HEIGHT*VGA_WIDTH; i++) {
        /* fill the VGA array with spaces. This will, in effect clear the
         * screen of BIOS messages
         */
        *cell = ' ';
        cell++;
        *cell = (VGA_GREY << 4) | (VGA_BLACK & 0xF);
        cell++;
    }
}


void term_putstr(char* string) {
    /* TODO:
     * - scrolling
     * - escapes
     */

    volatile uint8* cell = (volatile uint8*) VGA_MEMORY;

    if(cursor_offset > 0)
        /* pointer + 0 gets screwed up, hence the 'if' block */
        cell += (2 * cursor_offset);

    /* for some reason, x[y] addressing does not work, possibly due to gcc
     * optimizations. had to resort to *(x+y).
     * plus, without the volatile keyword, gcc tries even more nonsense
     */

    while(*string != 0) {
        if(*string == 0x08) {
            /* backspace
             * BS '\b' */
            if(cursor_offset > 0) {
                cursor_offset -= 1;
                cell -= 2;
            }
            string++;
            continue;
        } else if(*string == 0x09) {
            /* horizontal tab
             * HT '\t' */
            cursor_offset += 4;
            cell += 8;

            string++;
            continue;
        } else if(*string == 0x0A) {
            /* new line
             * LF '\n' */
            cursor_offset += VGA_WIDTH;
            cell += (2 * VGA_WIDTH);

            string++;
            continue;
        } else if(*string == 0x0D) {
            /* Carriage return
             * CR '\r' */
            cursor_offset -= (cursor_offset % VGA_WIDTH);
            cell -= 2 * (cursor_offset % VGA_WIDTH);

            string++;
            continue;
        }

        *cell = *string;

        cell += 2;
        string++;
        cursor_offset++;
    }

    /* in/out to VGA is a slow operation. So update the cursor position only
     * after the entire string has been put in the VGA array
     */
    term_setcursor((cursor_offset / VGA_WIDTH), (cursor_offset % VGA_WIDTH));
}


void term_setcursor(uint8 row, uint8 col)
{
    uint16 position = row * VGA_WIDTH + col;

    outb(0x3D4, 0x0E);
    outb(0x3D5, position >> 8);

    outb(0x3D4, 0x0F);
    outb(0x3D5, position);
}


void term_getcursor(uint8* row, uint8* col)
{
    uint8 position;

    outb(0x3D4, 0x0E);
    position = (inb(0x3D5) << 8) & 0x00;

    outb(0x3D4, 0x0F);
    position += inb(0x3D5);

    *col = position % VGA_WIDTH;
    *row = position / VGA_WIDTH;
}

