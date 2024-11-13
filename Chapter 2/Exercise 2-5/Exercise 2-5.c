/* Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.) */

#include <stdio.h>

#define MAXSTRING 1000

int my_getline(char line[], int limit);
int any(char s1[], char s2[]);

int main(void) {
	
	char s1[MAXSTRING];
	char s2[MAXSTRING];
	
	printf("Enter Original String:\n")
	my_getline(s1, MAXSTRING);
	
	printf("Enter Characters to Locate (First Appearance of Any):\n");
	my_getline(s2, MAXSTRING);
	
	printf("Location: %d", any(s1, s2));
	
	return 0;
}

int any(const char s1[], const char s2[]) {
	
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