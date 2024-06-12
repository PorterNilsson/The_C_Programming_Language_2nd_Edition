/* Write a program to print a histogram of the frequencies of different characters
in its input. */

#include <stdio.h>

#define SPACE 0
#define TAB 1
#define NEWLINE 2

main() {
    int i, c;

    /* We will have it track whitespace (spaces, tabs, and newlines), single digits, and letters (lowercase and capital). */
    int nwhite[3], , ndigit[10], nletter[52], nother;

    /* Initialize Arrays */
    for (i = 0; i < 3; ++i) {
        nwhite[i] = 0;
    }
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }
    for (i = 0; i < 52; ++i) {
        nletter[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        
        if (c == ' ') {
            ++nwhite[SPACE];
        }
        if (c == '\t') {
            ++nwhite[TAB];
        }
        if (c == '\n') {
            ++nwhite[NEWLINE];
        }
        
        for (i = 0; i < 10; ++i) {
            if (c == i) {
                ++ndigit[i];
            }
        }

        for (i = 0; i < 52; ++i) {
            if (c == ('a' + i)) {
                
            }
        }

    }
}