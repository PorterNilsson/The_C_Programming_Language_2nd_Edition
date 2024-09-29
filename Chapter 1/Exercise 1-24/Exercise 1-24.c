/* Write  a  program  to  check  a  C  program  for  rudimentary  syntax  errors  like  
unmatched  parentheses,  brackets  and  braces.  Don't  forget  about  quotes,  both  single  and  
double, escape sequences, and comments. (This program is hard if you do it in full 
generality.) */

#define _POSIX_C_SOURCE 0

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int limit); 

int main(void) {
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) != 0) {
        for (int i = 0; i < len; ++i) {
            putchar(line[i]);
        }
    }
    char letter = '\"';

}

int getline(char line[], int limit) {
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

/* TODO:
    1. Parentheses
        - Arbitrary depth
        - Opening and closing parentheses
    2. Brackets
        - Closing braces
        - Must match scope if combined with other braces
    3. Braces
    4. Quotes
        - " "
        - Look for unmatched quotes (Quotes don't nest unless escape sequenced)
    5. Escape sequences
        - /a, /b, /f, /n, /r, /t. /v, //, /?, /', /", /octal (up to 3 nums 0-7), /xhex (0-f) (upper or lowercase)
    6. Comments
        - //
        - multi line
    
    The Program
        - Reads output one line at a time.
        - First checks if we're inside of a mulit-line comment to potentially skip all other checks
            - We assume that multi line comments are always such, and that no code is contained on their same lines
            - Assume that single line comments either include the whole line or trail after legitimate code
        - Check for single line comment
*/
