/* Exercise  3-2.  Write  a  function  escape(s,t)  that  converts  characters  like  newline  and  tab  
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write 
a function for the other direction as well, converting escape sequences into the real characters. */

#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]);
void re_escape(char s[], char t[]);

int main(void) {

    char t[] = "Hello!\n\tHow are you?\n";
    /* String s is contrived, but it needs to be large enough to 
    account for 2 characters representing the escape sequences. */
    char s[strlen(t) + 1 + 3];

    escape(s, t);
    printf("Original String: %s\n", t);
    printf("New String: %s\n", s);

    printf("--------------------------------------\n");

    re_escape(t, s);
    printf("Original String: %s\n", s);
    printf("New String: %s\n", t);

    return 0;
}

void escape(char s[], char t[]) {
    unsigned int i = 0, j = 0;
    while(t[i] != '\0') {
        switch(t[i]) {
            case '\n':
                s[j] = '\\', s[j + 1] = 'n';
                j++;
                break;
            case '\t':
                s[j] = '\\', s[j + 1] = 't';
                j++;
                break;
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
    return;
}

void re_escape(char s[], char t[]) {
    /* This is clearly not the best use case for a switch statement as 
    identifying an escape character requires two indicies */
    unsigned int i = 0, j = 0;
    while (t[i] != '\0') {
        switch(t[i]) {
            case '\\':
                if (t[i + 1] == 'n') {
                    s[j] = '\n';
                    i++;
                }
                else if (t[i + 1] == 't') {
                    s[j] = '\t';
                    i++;
                }
                else {
                    s[j] = t[i];
                }
                break;
            default:
                s[j] = t[i];
        }           
        ++i, ++j;
    }
    s[j] = '\0';
    return;
}
