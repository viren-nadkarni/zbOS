#include "ctype.h"

int isalnum(int c) {

}

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

int isspace(int c) {

}

int isupper(int c) {

}

int isxdigit(int c) {
}

int tolower(int c) {

}

int toupper(int c) {

}

