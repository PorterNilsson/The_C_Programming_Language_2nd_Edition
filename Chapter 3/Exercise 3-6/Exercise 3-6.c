/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third 
argument is a minimum field width; the converted number must be padded with blanks on the 
left if necessary to make it wide enough. */

#include <stdio.h>
#include <limits.h>
#include <string.h>

#define FIELD_WIDTH 20

void itoa(int n, char s[], unsigned int width);
void reverse(char s[]);

int main(void) {

    char s1[FIELD_WIDTH];
    itoa(INT_MAX, s1, FIELD_WIDTH);
    printf("%s\n", s1);

    char s2[FIELD_WIDTH];
    itoa(INT_MIN, s2, FIELD_WIDTH);
    printf("%s\n", s2);

    return 0;
}

void itoa(int n, char s[], unsigned int width) {        
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

    char temp[width];
    strcpy(temp, s);
    unsigned int len = strlen(s) + 1;
    for (i = 0; i < width - len; ++i) {
        s[i] = ' ';
    }
    for (i = 0; i < len; ++i) {
        s[i + (width - len)] = temp[i];
    }
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
