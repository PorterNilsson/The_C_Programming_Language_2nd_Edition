/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2. */

/* Original Version:

void squeeze(char s[], int c) {       
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

*/

#include <stdio.h>

#define MAXSTRING 1000

void squeeze(char s1[], char s2[]);
int my_getline(char line[], int limit);

int main(void) {

    char s1[MAXSTRING];
    char s2[MAXSTRING];
    
    printf("Enter Original String:\n");
    my_getline(s1, MAXSTRING);
    
    printf("Enter String Containing Removal Characters:\n");
    my_getline(s2, MAXSTRING);
    
    squeeze(s1, s2);
    printf("Modified String: %s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int k = 0;
    while (s2[k] != '\0') {
        k++;
    }
    
    // printf("K: %d\n", k);

    int i, j;
    for (int c = 0; c < k; ++c) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[c])
                s1[j++] = s1[i];
        s1[j] = '\0';
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
