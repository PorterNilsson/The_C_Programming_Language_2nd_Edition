/* Write a program to print all input lines that are longer than 80 characters. */

#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);

main() {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) != 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }

}

int my_getline(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}