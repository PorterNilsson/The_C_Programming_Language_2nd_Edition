/* Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.) */

#include <stdio.h>

#define MAXSTRING 1000

int my_getline(char line[], int limit);
int any(const char s1[], const char s2[]);

int main(void) {
	
	char s1[MAXSTRING];
	char s2[MAXSTRING];
	
	printf("Enter Original String:\n");
	my_getline(s1, MAXSTRING);
	
	printf("Enter Characters to Locate (First Appearance of Any):\n");
	my_getline(s2, MAXSTRING);
	
	printf("Location (Zero-Indexed): %d\n", any(s1, s2));
	
	return 0;
}

int any(const char s1[], const char s2[]) {

    enum boolean {FALSE, TRUE};
    enum boolean match = FALSE;

    unsigned int len_s1 = 0;
    unsigned int len_s2 = 0;

    while (s1[len_s1] != '\0') {
        len_s1++;
    }
    while(s2[len_s2] != '\0') {
        len_s2++;
    }
    len_s1--, len_s2--;

    int first = len_s1;

    for (int i = 0; i < len_s2; i++) {
        for (int j = 0; j < len_s1; j++) {
            if (s1[j] == s2[i] && j < first) {
                first = j;
                match = TRUE;
            }
        }
    }

    if (match) {
        return first;
    }
    else {
        return -1;
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
