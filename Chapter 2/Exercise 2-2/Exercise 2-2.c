/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. */

/* Pertinent for loop:

for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i) 

*/ 

#include <stdio.h>

#define MAXLINE 1000

int main(void) {
	
	int i, c;
	char line[MAXLINE];
	
	for (i = 0; i < MAXLINE; ++i) {
		if ((c = getchar()) != EOF) {
			if (c != '\n') {
				line[i] = c;
			} 
			else {
				i = MAXLINE;
			}
		} 
		else {
			i = MAXLINE;
		}
	}

	printf("%s\n", line);

	return 0;
}
