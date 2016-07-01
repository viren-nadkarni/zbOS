#include "paging.h"
#include "def.h"

uint32 page_directory[1024] __attribute__((aligned(4096)));
uint32 page_table[1024]     __attribute__((aligned(4096)));

void paging_init() {
    /* TEMP: will be replaced by page allocator */
    for(uint32 i=0; i<1024; i++) {
        *(page_directory + i) = 0x00000002;
        *(page_table + i) = (i * 0x1000) | 0x3;
    }

    page_directory[0] = ((uint32) page_table) | 0x3;

    paging_load_directory(page_directory);
    paging_enable();
}

