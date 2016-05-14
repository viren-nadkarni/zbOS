#include "vga.h"
#include "tty.h"

#include <stdint.h>


void term_init() {
    volatile char* cell = (volatile char*) VGA_MEMORY;

    for(int i = 0; i < VGA_HEIGHT*VGA_WIDTH; i++) {
        /* fill the VGA array with spaces. This will, in effect clear the
         * of BIOS messages
         */
        *cell = ' ';
        cell++;
        *cell = VGA_GREY;
        cell++;
    }

    /* set the cursor to the first line */
    term_setcursor(0, 0);
}


void term_putstr(char* string) {
    volatile uint8_t* cell = (volatile uint8_t*) VGA_MEMORY;
    uint8_t array_offset, cursor_offset;
    int row, col;

    term_getcursor(&row, &col);
    cursor_offset = (row * VGA_HEIGHT) + col + 1;

    if(cursor_offset > 0)
        /* pointer + 0 gets screwed up, hence the 'if' block */
        cell += (2 * cursor_offset);

    /* for some reason, x[y] addressing does not work, possibly due to gcc 
     * optimizations. had to resort to *(x+y).
     * plus, without the volatile keyword, gcc tries even more nonsense
     */

    while(*string != 0) {
        switch(*string) {
            case '\n':
                string++;
                break;
            case '\t':
                string++;
                break;
        }

        *cell = *string;
        cell++;
        string++;

        *cell = VGA_GREY;
        cell++;

        cursor_offset += 1;
    }

    /* in out to VGA is a slow operation. So update the cursor position only
     * after the entire string has been put in the array
     */
    term_setcursor(cursor_offset / VGA_WIDTH, (cursor_offset % VGA_WIDTH) - 1);
}


void term_setcursor(int row, int col)
{
    unsigned short position = (row * 80) + col;
              
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(position & 0xFF));

    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char)((position >> 8) & 0xFF));
}


void term_getcursor(int* row, int* col)
{
    unsigned short position;
              
    outb(0x3D4, 0x0E);
    position = inb(0x3D5) << 8;

    outb(0x3D4, 0x0F);
    position += inb(0x3D5);

    *col = position % 80;
    *row = position / 80;
}


void outb(unsigned short port, unsigned char val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}


unsigned char inb(unsigned short port) {
    unsigned char val;

    asm volatile ("inb %1, %0" : "=a"(val) : "Nd"(port));

    return val;
}

