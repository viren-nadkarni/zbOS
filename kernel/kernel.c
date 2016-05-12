#include "tty.h"

void main() {
    char* video_memory = (char*) 0xb8000;       // first cell of video memory
    *video_memory = 'X';

    term_init();
    while(1);
}
