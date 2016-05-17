#ifndef TTY_H
#define TTY_H

void term_init(void);

void term_putchar(char);
void term_putstr(char*);

void term_setcursor(int, int);
void term_getcursor(int*, int*);

#endif
