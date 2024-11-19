/* Exercise  2-10.  Rewrite  the  function  lower,  which  converts  upper  case  letters  to  lower  case,  
with a conditional expression instead of if-else. */

#include <stdio.h>

char to_lower(char c);

int main(void) {

    printf("%c\n", to_lower('/'));
    printf("%c\n", to_lower('W'));
    printf("%c\n", to_lower('g'));

    return 0;
}

char to_lower(char c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}
