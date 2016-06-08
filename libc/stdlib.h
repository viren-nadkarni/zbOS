#ifndef STDLIB_H_
#define STDLIB_H_

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define NULL ((void *)0)

/* TODO:
 * - atoi
 * - itoa
 * - rand
 * - srand
 * - malloc
 * - free
 */

int isalpha(int);
int isdigit(int);

int atoi(const char*);
char *itoa(int, char*, int);

#endif
