/* Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text. */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int myGetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = myGetline(line, MAXLINE)) > 0) {
        printf("Length: %3d | Line: %s", len, line);

    }
    return 0;
}

/* getline: read a line into s, return length */
int myGetline(char s[],int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

