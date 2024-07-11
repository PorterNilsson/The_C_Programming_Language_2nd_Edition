/* Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define MAXLINE 1000
#define TAB_COLUMNS 4

int myGetline(char line[], int maxline);

main() {
    
    char line[MAXLINE];
    int len, i, offset, filler, j;

    while ((len = myGetline(line, MAXLINE)) != 0) {
        offset = 0;
        for (i = 0; i < len; ++i) {
            if (line[i] == '\t') {
                filler = TAB_COLUMNS - (offset % TAB_COLUMNS);
                for (j = 0; j < filler; ++j) {
                    putchar(' ');
                    ++offset;
                }
            }
            else {
                putchar(line[i]);
                ++offset;
            }
        }
    }

}

int myGetline(char s[],int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}