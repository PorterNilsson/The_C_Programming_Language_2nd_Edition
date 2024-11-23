/* Exercise  3-4.  In  a  two's  complement  number  representation,  our  version  of  itoa  does  not  
handle the largest negative number, that is, the value of n equal to -(2^wordsize-1). Explain why 
not. Modify it to print that value correctly, regardless of the machine on which it runs. */

/* Original function:

void itoa(int n, char s[]) {        
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

*/

/* Explanation:

    If the function recieves the maximum negative integer as value for n, negating (making positive) that number will
    result in integer overflow.

*/

#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {

    char s1[25];
    itoa(INT_MAX, s1);
    printf("%s\n", s1);

    char s2[25];
    itoa(INT_MIN, s2);
    printf("%s\n", s2);

    return 0;
}

void itoa(int n, char s[]) {        
    int i, sign;

    if ((sign = n) > 0)
        n = -n;
    i = 0;
    do {
        s[i++] = -(n % 10) + '0';
    } while ((n /= 10) < 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    --i;

    for (int j = 0; j <= i / 2; ++j) {
        char temp = s[j];
        s[j] = s[i - j], s[i - j] = temp;
    }

    return;
}
