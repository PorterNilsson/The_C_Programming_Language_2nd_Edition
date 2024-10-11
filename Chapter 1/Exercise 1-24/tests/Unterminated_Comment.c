/* Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. *

#include <stdio.h>

#define MAX_LINE 1000
#define LONG_LINE 50

int myGetline(char line[], int maxline);

main() {
    int len, i, cut, printed, whitespace;
    char line[MAX_LINE];

    while ((len = myGetline(line, MAX_LINE)) != 0) {
        printed = 0;
        cut = 0;
        while (len > 0) {
            whitespace = 0;
            if (len > LONG_LINE) {

                if ((cut % LONG_LINE) == 0) {
                    cut += LONG_LINE;
                }
                else {
                    cut += (LONG_LINE - (cut % LONG_LINE));
                }

                while (line[cut + whitespace] == ' ') {
                    ++whitespace;
                }

                for (i = 0 + printed; i < cut; ++i) {
                    putchar(line[i]);
                }
                if (line[i] != '\n') {
                    putchar('\n');
                }

                cut += whitespace;
                len -= (cut - printed);
                printed = cut;
            }
            else {
                for (i = 0 + printed; i < len + printed; ++i) {
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