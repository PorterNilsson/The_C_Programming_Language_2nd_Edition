/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */

#include <stdio.h>

# define MAXLINE 1000

int my_getline(char line[], int limit);
int htoi(const char hex_string[]);

int main(void) {
	
	char str[MAXLINE];
	my_getline(str, MAXLINE);

	printf("Original String: %s\n", str);
	printf("Conversion Result: %d\n", htoi(str));

	return 0;
}

int htoi(const char hex_string[]) {
	
	enum boolean {FALSE, TRUE};
	
	int i = 0, integer = 0;
	enum boolean prefix = FALSE;
	int stop_index = 0;
	
	if (hex_string[1] == 'x' || hex_string[1] == 'X') {
		prefix = TRUE;
		stop_index = 2;
	}
	
	while (hex_string[i] != '\0') {
			i++;
		}
		
	if (!prefix && i > 4) {
		printf("String too long!\n");
		return -1;
	}
	else if (prefix && i > 6) {
		printf("String too long!\n");
		return -1;
	}
	

	int numeric_magnitude = 1;
	for (i = i - 1; i >= stop_index; i--) {
		// printf("i = %d\n", i);
		if (hex_string[i] >= '0' && hex_string[i] <= '9') {
			integer = integer + ((hex_string[i] - '0') * numeric_magnitude);
			// printf("%d\n", (hex_string[i] - '0'));
		}
		else if (hex_string[i] >= 'a' && hex_string[i] <= 'f') {
			integer = integer + ((hex_string[i] - 'a' + 10) * numeric_magnitude);
			// printf("%d\n", (hex_string[i] - 'a' + 10));
		}
		else if (hex_string[i] >= 'A' && hex_string[i] <= 'F') {
			integer = integer + ((hex_string[i] - 'A' + 10) * numeric_magnitude);
			// printf("%d\n", (hex_string[i] - 'A' + 10));
		}
		numeric_magnitude = numeric_magnitude * 16;
		// printf("Integer: %d\n", integer);
	}

	return integer;
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
    ret