/* Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none. */

/* Original function:

int strindex(char s[], char t[]) {
	int i, j, k;
	
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
		}
	return -1;
}

*/

#include <stdio.h>

int strindex(char s[], char t[]);

int main(void) {
	
	char s[] = "First xyz and second xyz";
	char t[] = "xyz";
	
	printf("%d\n", strindex(s, t));
	
	return 0;
}

int strindex(char s[], char t[]) {
	int i, j, k;
	int current_rightmost = -1;
	
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			current_rightmost = i;
		}
	return current_rightmost;
}
