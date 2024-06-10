/* Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank. */

#include <stdio.h>

main() {
    int c, previous_char;

    /* To make sure that initial value of previous_char isn't simply garbage and risk c being equal initially. */
    previous_char = EOF;

    while ((c = getchar()) != EOF) {

        if (c == ' ') {
            if (c == previous_char)
            ;
            else {
                printf("%c", c);
            }
        }
        else {
            printf("%c", c);
        }

        previous_char = c;
    }
}