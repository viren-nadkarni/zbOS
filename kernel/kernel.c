#include "tty.h"

void main() {
    term_init();
    term_putchar('X');

    while(1);
}
