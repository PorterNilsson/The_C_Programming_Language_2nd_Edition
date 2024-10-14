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

    int in_multi_line_comment = 0, in_double_quote = 0, in_single_quote = 0;
    int opening_parenthesis = 0, closing_parenthesis = 0;
    int opening_bracket = 0, closing_bracket = 0;
    int opening_brace = 0, closing_brace = 0;

    int syntax_error = 0, lines_checked = 1, syntax_error_line = 0, state_changed = 0;

    while((len = getline(line, MAXLINE)) != 0 && !syntax_error) {
        for (int i = 0; i < len; ++i) {
            if (!in_multi_line_comment && !in_double_quote && !in_single_quote) {
                /* Multi-line comment check */
                if (i < len - 1 && !state_changed) {
                    if (line[i] == '/' && line[i + 1] == '*') {
                        in_multi_line_comment = 1;
                        state_changed = 1;
                        syntax_error_line = lines_checked;
                    }
                }

                /* Double quote check */
                if (!state_changed && line[i] == '\"') {
                    in_double_quote = 1;
                    state_changed = 1;
                    syntax_error_line = lines_checked;
                }

                /* Single quote check */
                if (!state_changed && line[i] == '\'') {
                    in_single_quote = 1;
                    state_changed = 1;
                    syntax_error_line = lines_checked;
                }
            }

            if (i < len - 1 && in_multi_line_comment && !state_changed) {
                if (line[i] == '*' && line[i + 1] == '/') {
                    in_multi_line_comment = 0;
                    state_changed = 1;
                }
            }
            
            if (!state_changed && in_double_quote && (lines_checked == syntax_error_line)) {
                if (line[i] == '\"') {
                    in_double_quote = 0;
                    state_changed = 1;
                }
            }

            if (!state_changed && in_single_quote) {
                if (line[i] == '\'') {
                    in_single_quote = 0;
                    state_changed = 1;
                }
            }
            state_changed = 0;
        }
        ++lines_checked;
    }

    if (in_multi_line_comment) {
        printf("Syntax error starting on line %d: Unterminated multi-line comment\n", syntax_error_line);
    }
    if (in_double_quote) {
        printf("Syntax error starting on line %d: Unterminated double quote\n", syntax_error_line);
    }
    if (in_single_quote) {
        printf("Syntax error starting on line %d: Unterminated single quote\n", syntax_error_line);
    }

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
            We assume that multi line comments are always such, and that no code is contained on their same lines
            Assume that single line comments either include the whole line or trail after legitimate code
        - Check for single line comment
        - if we're not in a comment:
            Look for any of the 3 brackets, braces, quotes, etc.
            If any of the 3 don't have a matching number of open and closed brackets, then it's not legal ("illegal ( paraenteses[ )"
        - For escape sequences, check if it's in a legal form...
            legal letters
            up to three octal or two hex
*/
