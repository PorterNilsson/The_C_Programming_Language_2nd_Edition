/* Write  a  program  to  remove  all  comments  from  a  C  program.  Don't  forget  to  
handle quoted strings and character constants properly. C comments don't nest. */

#include <stdio.h>

#define MAX_LINE 1000

int myGetline(char line[], int maxline);

main() {
    // C comments look like /* comment */
    /**/ // Edge case
    int len, inComment = 0, changed = 0;
    char line[MAX_LINE];

    while ((len = myGetline(line, MAX_LINE)) != 0) {
        for (int i = 0; i < len; ++i) {
            if (i + 1 < len){
                if (line[i] == '/' && line[i + 1] == '*') {
                    inComment = 1;
                    changed = 1;
                }
                if (line[i] == '*' && line[i + 1] == '/' && !changed) {
                    inComment = 0;
                    i += 2;
                }
                changed = 0;
            }
            if (!inComment) {
                putchar(line[i]);
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