#ifndef PAGING_H_
#define PAGING_H_

#include "def.h"

extern void paging_enable();
extern void paging_load_directory(uint32*);

struct table_entry {
    uint32 present          : 1;    /* present */
    uint32 read_write       : 1;    /* read/write */
    uint32 user_supervisor  : 1;    /* user/supervisor */
    uint32 write_through    : 1;    /* write through */
    uint32 cache_disabled   : 1;    /* cache disabled */
    uint32 accessed         : 1;    /* accessed */
    uint32 dirty            : 1;    /* dirty */
    uint32 _padding         : 1;    /* always 0 */
    uint32 global           : 1;    /* global */
    uint32 _reserved        : 3;
    uint32 address          : 20;   /* physical page address */
};


struct directory_entry {
    uint32 present          : 1;
    uint32 read_write       : 1;
    uint32 user_supervisor  : 1;
    uint32 write_through    : 1;
    uint32 cache_disabled   : 1;
    uint32 accessed         : 1;
    uint32 _padding         : 1;    /* always 0 */
    uint32 size             : 1;    /* 0 for 4kb */
    uint32 ignored          : 1;    /* ignored */
    uint32 _reserved        : 3;
    uint32 address          : 20;   /* page table 4kb aligned address */
};

void paging_init();
void paging_fault_handler();
void *alloc_frame();

#endif

