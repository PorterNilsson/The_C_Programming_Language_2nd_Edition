/* Write a program to print a histogram of the frequencies of different characters
in its input. */

#include <stdio.h>

main() {
    int i, c;
    int nwhite[3], nletter[52], ndigit[10], nother;

    /* Initialize Arrays */
    for (i = 0; i < 3; ++i) {
        nwhite[i] = 0;
    }
    for (i = 0; i < 52; ++i) {
        nletter[i] = 0;
    }
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    
}