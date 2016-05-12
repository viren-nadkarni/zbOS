#include "vga.h"
#include "tty.h"

void term_init() {
/* term_init
 * ---------
 *  initialise the terminal by clearing the screen
 */

    unsigned int* cell = (unsigned int*) VGA_MEMORY;

    for(int i=0; i<VGA_HEIGHT; ++i) {
        for(int j=0; j<VGA_WIDTH; ++j) {
            *cell++ = ' ';
            *cell++ = VGA_BLACK;
        }
    }
}

