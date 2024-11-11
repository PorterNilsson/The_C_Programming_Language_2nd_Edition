/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */

#include <stdio.h>

int main(void) {
	
	

	return 0;
}

int htoi(char hex_string[]) {
	
	enum boolean {FALSE, TRUE};
	
	int i = 0, integer = 0;
	boolean prefix = FALSE;

	
	if (hex_string[1] == 'x' || hex_string[1] == 'X') {
		prefix = TRUE;
	}
	
	while (hex_string[i] != '\0') {
			i++;
		}
		
	if (!prefix && i > 4) {
		return -1;
	}
	else if (prefix && i > 6) {
		return -1;
	}
	
	
	for (i, i >= 0; i--) {
		if (hex_string[i] >= '0' && hex_string[i] <= '9') {
			integer = integer + (hex_string[i] - '0');
		}
		
	}

}