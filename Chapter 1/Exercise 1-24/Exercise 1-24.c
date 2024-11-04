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
            if (!in_multi_line_comment && !in_double_quote && !in_single_quote && !syntax_error) {
                /* Multi-line comment check */
                if (i < len - 1) {
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

                /* Curly Brace checks */
                if (!state_changed && line[i] == '{') {
                    opening_brace++;
                }
                if (!state_changed && line[i] == '}') {
                    closing_brace++;
                }
                /* Bracket checks */
                if (!state_changed && line[i] == '[') {
                    opening_bracket++;
                }
                if (!state_changed && line[i] == ']') {
                    closing_bracket++;
                }
                /* Parentheses checks */
                if (!state_changed && line[i] == '(') {
                    opening_parenthesis++;
                }
                if (!state_changed && line[i] == ')') {
                    closing_parenthesis++;
                }
				
				if (!state_changed && line[i] == '\\') {
					if (line[i + 1] != 'a' || line[i + 1] != 'b' || line[i + 1] != 'f' || line[i + 1] != 'n' || line[i + 1] != 'r' || line[i + 1] != 't' || line[i + 1] != 'v' || line[i + 1] != '\\' || line[i + 1] != '?' || line[i + 1] != '\'' || line[i + 1] != '"' || line[i + 1] != 'x') {
                        syntax_error = 1;
                        i++;
                        syntax_error_line = lines_checked;
				}
            }

            /* Make sure comments and quotes terminal */
            if (!state_changed) {
                if (i < len - 1 && in_multi_line_comment) {
                    if (line[i] == '*' && line[i + 1] == '/') {
                        in_multi_line_comment = 0;
                    }
                }
                
                if (in_double_quote && (lines_checked == syntax_error_line)) {
                    if (line[i] == '\"') {
                        in_double_quote = 0;
                    }
                }

                if (in_single_quote && (lines_checked == syntax_error_line)) {
                    if (line[i] == '\'') {
                        in_single_quote = 0;
                    }
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
    /* This program simply looks for an equal number of opening and closing braces */
    if (opening_bracket != closing_bracket) {
        printf("Number of opening and closing brackets do not match.\n");
    }
    if (opening_brace != closing_brace) {
        printf("Number of opening and closing braces do not match.\n");
    }
    if (opening_parenthesis != closing_parenthesis) {
        printf("Number of opening and closing parentheses do not match.\n");
    }
    
    /* Error checking for escape sequences doesn't include octal (for time purposes) */
    if (syntax_error) {
        printf("Syntax error on line %d: Invalid escape sequence", syntax_error_line);
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