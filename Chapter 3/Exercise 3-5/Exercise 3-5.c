/* Exercise  3-5.  Write  the  function  itob(n,s,b)  that  converts  the  integer  n  into  a  base  b 
character representation in the string s. In particular, itob(n,s,16) formats s as a 
hexadecimal integer in s. */

#include <stdio.h>
#include <limits.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {

    char s1[25];
    itob(INT_MAX, s1, 16);
    printf("%s\n", s1);
    char s2[25];
    itob(INT_MAX, s2, 2);
    printf("%s\n", s2);

    char s3[25];
    itob(INT_MIN, s3, 16);
    printf("%s\n", s3);
    char s4[25];
    itob(INT_MIN, s4, 2);
    printf("%s\n", s4);

    return 0;
}

void itob(int n, char s[], int b) {
    int i, sign;

    if (b > 36) {
        return;
    }

    if ((sign = n) > 0)
        n = -n;
    i = 0;
    do {
        // printf("N = %d, N %% b = %d\n", n, (n % b));
        int mod = -(n % b);
        if (mod < 10) {
            s[i++] = mod + '0';
        }
        else {
            s[i++] = mod - 10 + 'a';
        }
        // printf("%c\n", s[i - 1]);
    } while ((n /= b) < 0);
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
