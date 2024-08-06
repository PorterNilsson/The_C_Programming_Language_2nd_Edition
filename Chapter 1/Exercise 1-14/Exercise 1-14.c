/* Write a program to print a histogram of the frequencies of different characters
in its input. */

#include <stdio.h>

#define SPACE 0
#define TAB 1
#define NEWLINE 2

main() {
    int i, j, c;

    /* We will have it track whitespace (spaces, tabs, and newlines), single digits, and letters (lowercase and capital). */
    int nwhite, ndigit[10], nlower[26], nupper[26], nother;

    /* Initialize Values */
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }
    for (i = 0; i < 26; ++i) {
        nlower[i] = 0;
    }
    for (i = 0; i < 26; ++i) {
        nupper[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        
        if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        }
        else if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        }
        else if (c >= 'a' && c <= 'z') {
            ++nlower[c - 'a'];
        }
        else if (c >= 'A' && c <= 'Z') {
            ++nupper[c - 'A'];
        }
        else {
            ++nother;
        }

    }

    printf("%3c|", 'w');
    for (i = 0; i < nwhite; ++i) {
        putchar('*');
    }
    putchar('\n');
    for (i = 0; i < 10; ++i) {
        printf("%3d|", i);
        for (j = 0; j < ndigit[i]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }
    for (i = 0; i < 26; ++i) {
        printf("%3c|", i + 'a');
        for (j = 0; j < nlower[i]; ++j) {
            putchar('*'); 
        }
        putchar('\n');
    }
    for (i = 0; i < 26; ++i) {
        printf("%3c|", i + 'A');
        for (j = 0; j < nupper[i]; ++j) {
            putchar('*'); 
        }
        putchar('\n');
    }

}