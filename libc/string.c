#include "string.h"

int strlen(char *string) {
    int length = 0;

    while(*string != 0) {
        string++;
        length++;
    }

    return length;
}

char *strrev(char *string) {
    int length = strlen(string);
    int c;

    for(int i=0, j=length-1; i<j; i++, j--) {
        c = string[i];
        string[i] = string[j];
        string[j] = c;
    }

    return string;
}

