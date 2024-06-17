/* Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int limit);
void reverse(char line[], char reverse[], int length);

main() {
    char line[MAXLINE], reversed[MAXLINE];
    int len;

    while ((len = my_getline(line, MAXLINE)) != 0) {
        reverse(line, reversed, len);
        printf("%s", reversed);
    }
}

int my_getline(char line[], int limit) {
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

void reverse(char line[], char reverse[], int length) {
    int i, j;

    j = 0;
    if (length > 1) {
        for (i = length - 2; i >= 0; --i) {
            reverse[j] = line[i];
            ++j;
        }
        reverse[j] = '\n';
    }
    else {
        reverse[j] = '\n';
    }
    ++j;
    reverse[j] = '\0';
}




