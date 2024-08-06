/* Write a program to print all input lines that are longer than 80 characters. */

#include <stdio.h>
#define MAXLINE 1000

int myGetline(char line[], int limit);

main() {
    int len;
    char line[MAXLINE];

    while ((len = myGetline(line, MAXLINE)) != 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }

}

int myGetline(char line[], int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}