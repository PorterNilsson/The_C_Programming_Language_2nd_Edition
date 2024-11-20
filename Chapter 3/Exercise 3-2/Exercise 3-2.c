/* Exercise  3-2.  Write  a  function  escape(s,t)  that  converts  characters  like  newline  and  tab  
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write 
a function for the other direction as well, converting escape sequences into the real characters. */

/* I won't bother writing the function to convert back here because it's trivial, 
and a conversion in either direction which conserves string size is impossible. It's not a great exercise. */

#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]);

int main(void) {

    char t[] = "Hello!\n\tHow are you?\n";
    char s[strlen(t) + 1];

    escape(s, t);

    printf("Original String: %s\n", t);
    printf("New String: %s\n", s);

    return 0;
}

void escape(char s[], char t[]) {
    unsigned int i = 0;
    while(t[i] != '\0') {
        switch(t[i]) {
            case '\n':
                s[i] = '\\';
                break;
            case '\t':
                s[i] = '\\';
                break;
            default:
                s[i] = t[i];
                break;
        }
        i++;
    }
    s[i] = '\0';
    return;
}
