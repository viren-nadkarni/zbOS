#include "stdlib.h"
#include "string.h"

int isalpha(int c) {
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) {
        return 1;
    }
    return 0;
}

int isdigit(int c) {
    if( c >= '0' && c <= '9' )
        return 1;
    else
        return 0;
}

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
    /* TODO: implement radix */

    int sign = 1, i = 0;

    if(value < 0) {
        sign = -1;
    }

    do {
        string[i++] = value % 10 + '0';
    } while( (value /= 10) > 0 );

    if(sign < 0)
        string[i++] = '-';

    return strrev(string);
}

