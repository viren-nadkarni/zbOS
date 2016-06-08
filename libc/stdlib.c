#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int atoi(const char *c) {
    int result = 0, sign = 1;

    if( *c == '+' )
        c++;

    if( *c == '-' ) {
        sign = -1;
        c++;
    }

    while(isdigit(*c)) {
        result *= 10;
        result += (int)(*c - '0');
        c++;
    }

    return result * sign;
}

char *itoa(int value, char *string, int radix) {
    /* recommended length of 'string' is 18 bytes on 16-bit and 34 on 32-bit platforms */

    char map[] = "0123456789ABCDEF";
    int sign = 1, i = 0;

    if(value < 0)
        sign = -1;

    do {
        string[i++] = map[value % radix];
    } while( (value /= radix) > 0 );

    if(radix == 10 && sign < 0)
        string[i++] = '-';

    return strrev(string);
}

