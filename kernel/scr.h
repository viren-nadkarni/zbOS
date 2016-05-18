#ifndef SCR_H_
#define SCR_H_

#include "def.h"

void term_init(void);
void term_clear(void);
void term_scroll(void);

void term_putchar(char);
void term_putstr(char*);

void term_setcursor(uint8, uint8);
void term_getcursor(uint8*, uint8*);

#endif
