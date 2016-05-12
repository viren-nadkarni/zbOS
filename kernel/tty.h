#ifndef TTY_H
#define TTY_H
#include <stddef.h>

void term_init(void);
void term_putchar(char c);
void term_write(const char* data, size_t size);
void term_writestr(const char* data);

#endif
