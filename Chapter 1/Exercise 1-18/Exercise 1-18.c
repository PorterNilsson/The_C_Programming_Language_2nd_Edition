/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000

int myGetline(char line[], int limit);

main () {
    int len, i;
    char line[MAXLINE];

    while ((len = myGetline(line, MAXLINE)) != 0) {
        if (len > 1) {
            i = 1; /* To account for \n index */
            while (line[len - i] == ' ' || line[len - i] == '\t') {
                len = len - i;
                --i;
            }
            for (i = 0; i < len - 1; ++i) {
                printf("%c", line[i]);
            }
            putchar('\n');
        }
    }
}

int myGetline(char line[], int limit) {
    int i, c;

    for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}