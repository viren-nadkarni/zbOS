#ifndef STDLIB_H_
#define STDLIB_H_

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define NULL ((void *)0)

/* TODO:
 * - rand
 * - srand
 * - malloc
 * - free
 */

int atoi(const char*);
char *itoa(int, char*, int);

#endif
