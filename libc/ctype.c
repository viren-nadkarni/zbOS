#include "ctype.h"
#include "string.h"
#include "stdbool.h"

int isalnum(int c) {
    if( isalpha(c) || isdigit(c) )
        return true;
    return false;
}

int isalpha(int c) {
    if( isupper(c) || islower(c) )
        return true;
    return false;
}

int isdigit(int c) {
    if( c >= '0' && c <= '9' )
        return true;
    return false;
}

int isspace(int c) {
    if( c == ' ' )
        return true;
    return false;
}

int isupper(int c) {
    if( c >= 'A' && c <= 'Z' )
        return true;
    return false;
}

int islower(int c) {
    if( c >= 'a' && c <= 'z' )
        return true;
    return false;
}

int isxdigit(int c) {
    char hexmap[] = "0123456789ABCDEFabcdef";
    if(isalnum(c))
        for(int i=0; i<strlen(hexmap); ++i)
            if(c == hexmap[i])
                return true;
    return false;
}

int tolower(int c) {
    if(isalpha(c))
        return (c + 20);
    return c;
}

int toupper(int c) {
    if(isalpha(c))
        return (c - 20);
    return c;
}

