/* Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent. */

/* Original function:

double atof(char s[]) {
	double val, power;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}

*/

#include <stdio.h>

double atof(char s[]);

int main(void) {
	
	char s[] = "123.456";
	printf("Float (123.456) = %fd
	
	return 0;
}

double atof(char s[]) {
	double val, power;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	val = sign * val / power;
	
	/* Extension—checking for scientific notation */
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	else
		return val;
		
	int sci_notation;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (sci_notation = 0; isdigit(s[i]); i++) {
		sci_notation = 10.0 * sci_notation + (s[i] - '0');
	}
	for (i = 0; i < sci_notation; ++i) {
		if (sign == 1)
			val *= 10;
		else
			val /= 10;
	}
	return val;
}

