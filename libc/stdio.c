#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "scr.h"

int putchar(char c) {
    char out[] = {c, 0};
    term_putstr(out);
    return 1;
}

int printf(const char *format, ...) {
    va_list argptr;
    char s[48], *str;
    int c, num, outcount = 0;

    va_start(argptr, format);

    while(*format != 0) {
        if(*format != '%') {
            putchar(*format);
        } else {
            format++;

            switch(*format) {
                case '%':
                    putchar('%');
                    break;

                /* char */
                case 'c':
                    c = va_arg(argptr, int);
                    putchar(c);
                    break;

                /* signed int */
                case 'd':
                case 'i':
                    num = va_arg(argptr, int);
                    itoa(num, s, 10);
                    term_putstr(s);
                    break;

                /* float */
                /* TODO */
                case 'f':
                case 'F':
                    term_putstr("unimplemented");
                    break;

                /* string of chars */
                case 's':
                    str = va_arg(argptr, char*);
                    term_putstr(str);
                    break;

                /* unsigned hex */
                case '#':
                    term_putstr("0x");
                    format++;
                case 'x':
                case 'X':
                    num = va_arg(argptr, int);
                    itoa(num, s, 16);
                    term_putstr(s);
                    break;

                default:
                    break;
            }
        }
        format++;
        outcount++;
    }
    va_end(argptr);
    return outcount;
}

