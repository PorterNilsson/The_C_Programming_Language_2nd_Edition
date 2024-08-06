/* Write a program that prints its input one word per line */

#include <stdio.h>

#define IN 1 /* Inside of a word. */
#define OUT 0 /* Outside of a word. */

main() {
    int c, state;

    state = OUT; /* The input might start with whitespace */
    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) { /* State swaps from in -> out */
                putchar('\n'); 
                state = OUT;
            }
        }
        else {
            state = IN;
        }

        if (state == IN) {
            putchar(c);
        }
    }
}