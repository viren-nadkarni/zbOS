#include "vga.h"
#include "tty.h"

void term_init() {
/* term_init
 * ---------
 *  initialise the terminal by clearing the screen
 */

    char* cell = (char*) VGA_MEMORY;

    for(int i=0; i<VGA_HEIGHT; ++i) {
        for(int j=0; j<VGA_WIDTH; ++j) {
            *cell = ' ';
            cell++;
            *cell = VGA_BLACK;
            cell++;
        }
    }
}


void term_putchar(char ch) {
/* term_putchar
 * ------------
 *  print a single character on the screen
 *
 *  ch: character to print
 */

    char* cell = (char*) VGA_MEMORY;
    
    *cell = ch;
    cell++;
    *cell = VGA_LIGHT_GREY;
}
