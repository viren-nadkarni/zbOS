#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "ctype.h"
#include "string.h"
#include "scr.h"

int putchar(char c) {
    char out[] = {c, 0};
    term_putstr(out);
    return 1;
}

int printf(const char *format, ...) {
    va_list argptr;
    char s[48], *str, fill_char = ' ';
    int c, num, outcount = 0, fill_len = 0;

    va_start(argptr, format);

    while(*format != 0) {
        if(*format != '%') {
            putchar(*format);
        } else {
            format++;
			
            /* we will jump all flags and widths. these will be read later */
            while(isdigit(*format) || *format == '#') {
                format++;
            }

            if(*format == '%') {
                putchar('%');
            }
            /* char */
            else if(*format == 'c') {
                c = va_arg(argptr, int);
                putchar(c);
            }
            /* signed int */
            else if(*format == 'i' || *format == 'd') {
                while(*(format - 1) != '%') {
                    format--;
                } 

                if(*format == '0') {
                    fill_char = '0';
                    format++;
                }

                if(*format >= '1' && *format <= '9') {
                    char ct[8] = { 0 };

                    for(int k=0; isdigit(*format); k++) {
                        ct[k] = *format;
                        format++;
                    }
                    fill_len = atoi(ct);
                }

                num = va_arg(argptr, int);
                itoa(num, s, 10);
                if(fill_len) {
                    for(int k=0; k<fill_len; k++) {
                        putchar(fill_char);
                    }
                    fill_len = 0;
                    fill_char = ' ';
                    term_seek(-strlen(s));
                }
                term_putstr(s);
            }
            /* float */
            else if(*format == 'f' || *format == 'F') {
                /* TODO */
                term_putstr("unimplemented");
            }
            /* string */
            else if(*format == 's') {
                str = va_arg(argptr, char*);
                term_putstr(str);
            }
            /* unsigned hex */
            else if(*format == 'x' || *format == 'X') {
                while(*(format - 1) != '%') {
                    format--;
                } 

                if(*format == '#') {
                    term_putstr("0x");
                    format++;
                }

                if(*format == '0') {
                    fill_char = '0';
                    format++;
                }

                if(*format >= '1' && *format <= '9') {
                    char ct[8] = { 0 };

                    for(int k=0; isdigit(*format); k++) {
                        ct[k] = *format;
                        format++;
                    }
                    fill_len = atoi(ct);
                }

                num = va_arg(argptr, int);
                itoa(num, s, 16);
                if(fill_len) {
                    for(int k=0; k<fill_len; k++) {
                        putchar(fill_char);
                    }
                    fill_len = 0;
                    fill_char = ' ';
                    term_seek(-strlen(s));
                }
                /* TODO: implement `x' lowercase and `X' uppercase */
                term_putstr(s);
			}
		}
        
        format++;
        outcount++;
        for(int l=0; l<48; l++)
            s[l] = 0;
    }
    va_end(argptr);
    return outcount;
}

