/* Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. */

#include <stdio.h>

#define MAX_LINE 1000
#define LONG_LINE 50

int myGetline(char line[], int maxline);

main() {
    int len, i, cut = LONG_LINE, printed;
    char line[MAX_LINE];

    while ((len = myGetline(line, MAX_LINE)) != 0) {
        while (len > 0) {
            printed = 0;
            if (len > LONG_LINE) {
                cut += LONG_LINE;
                while (line[cut] == ' ') {
                    ++cut;
                }
                for (i = 0 + printed; i < cut; ++i) {
                    putchar(line[i]);
                }
                printed += cut;
                len -= printed;
            }
            else {
                for (i = 0; i < len; ++i) {
                    putchar(line[i]);
                }
                len = 0;
            }
        }
    }
}

int myGetline(char line[], int maxline) {
    int i, c;
    for (i = 0; (c = getchar()) != '\n' && c != EOF && i < maxline - 1; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}