/* Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference? */

/* Answer: When a tab or a single blank would suffice, a blank should be given preference, 
otherwise normal single-spaced syntax of common language would be tabbed in a random manner 
corresponding to how the words lined up with the tab stops. */

#include <stdio.h>

#define MAXLINE 1000
#define TAB_COLUMNS 4

int myGetline(char line[], int maxline);

main() {
    int len, i, inSpace, spaces = 0, offset;
    char line[MAXLINE];

    while ((len = myGetline(line, MAXLINE)) != 0) {
        inSpace = 0;
        for (i = 0; i < len; ++i) {
            if (line[i] == ' ') {
                inSpace = 1;
                ++spaces;
            }
            else {
                if (inSpace) {
                    offset = TAB_COLUMNS - ((i - spaces) % TAB_COLUMNS);
                    if (spaces > 1 && spaces >= offset) {
                        putchar('\t');
                        spaces = spaces - offset;
                    }
                    while (spaces > 1 && spaces >= TAB_COLUMNS) {
                        putchar('\t');
                        spaces = spaces - TAB_COLUMNS;
                    }
                    while (spaces > 0) {
                        putchar(' ');
                        --spaces;
                    }

                    inSpace = 0;
                }
 
                printf("%c", line[i]);
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