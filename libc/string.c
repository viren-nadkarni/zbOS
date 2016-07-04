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

char *strcpy(char *dest, const char *src) {
    for(int i=0; src[i]!='\0'; i++)
        dest[i] = src[i];

    return dest;
}

char *strcat(char *dest, const char *src) {
    int s=strlen(dest);
    for(int i=0; src[i]!='\0'; i++) {
        dest[i+s] = src[i];
    }

    return dest;
}
