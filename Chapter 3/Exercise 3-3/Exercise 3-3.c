/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in 
the  string  s1  into  the  equivalent  complete  list  abc...xyz  in  s2.  Allow  for  letters  of  either  
case  and  digits,  and  be  prepared  to  handle  cases  like  a-b-c  and  a-z0-9  and  -a-z.  Arrange  
that a leading or trailing - is taken literally. */

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main(void) {

    char s1[] = "This string is a test:\n"
                "a to z a-z\n"
                "z to a z-a\n"
                "A to Z A-Z\n"
                "Z to A Z-A\n"
                "A to z (should follow the case of the first letter) A-z\n"
                "Z to a (should follow the case of the first letter) Z-a\n"
                "a to Z (should follow the case of the first letter) a-Z\n"
                "z to A (should follow the case of the first letter) z-A\n"
                "a to b to c a-b-c\n"
                "z to y to x z-y-x\n"
                "0 to 9 0-9\n"
                "9 to 0 9-0\n"
                "0 to 1 to 2 0-1-2\n"
                "9 to 8 to 7 9-8-7\n"
                "A to Z and 0 to 9 A-Z0-9\n"
                "Z to A and 9 to 0 Z-A9-0\n"
                "0 to 9 and a to z 0-9a-z\n"
                "9 to 0 and z to a 9-0z-a\n"
                "-A to Z (should ignore leading dash) -A-Z\n"
                "-Z to A (should ignore leading dash) -Z-A\n"
                "a to z- (should ignore trailing dash) a-z-\n"
                "z to a- (should ignore trailing dash) z-a-\n"
                "Monster Example: -A to f to g to X to 9 to 8 to 1 to 9 to l to I to z-\n"
                "Should expand to *literally* dash A through f through X, dash, 9 through 1 through 9, dash, l through I through z, dash\n"
                "-A-f-g-X-9-8-1-9-l-I-z-";
    /* Arbitrarily large string to hold the expansion */
    char s2[1000] = {' '};

    expand(s1, s2);
    // printf("\n--------------------------------------\n\n");
    printf("%s\n", s1);
    printf("\n--------------------------------------\n\n");
    printf("%s\n", s2);

    return 0;
}

void expand(char s1[], char s2[]) {

    int j = 0;
    for (int i = 0; s1[i] != '\0'; ++i, ++j) {
        if (s1[i] == '-' && s1[i + 1] != '\0') {
            if ((s1[i - 1] >= 'a' && s1[i - 1] <= 'z') && isalpha(s1[i + 1])) {
                if (s1[i - 1] <= tolower(s1[i + 1])) {
                    for (int k = s1[i - 1] + 1; k <= tolower(s1[i + 1]) - 1; ++k, ++j) {
                        s2[j] = k;
                        // printf("%c", s2[j]);
                    }
                    --j;
                }
                else {
                    for (int k = s1[i - 1] - 1; k >= tolower(s1[i + 1]) + 1; --k, ++j) {
                        s2[j] = k;
                        // printf("%c", s2[j]);
                    }
                    --j;
                }
            }
            else if ((s1[i - 1] >= 'A' && s1[i - 1] <= 'Z') && isalpha(s1[i + 1])) {
                if (s1[i - 1] <= toupper(s1[i + 1])) {
                    for (int k = s1[i - 1] + 1; k <= toupper(s1[i + 1]) - 1; ++k, ++j) {
                        s2[j] = k;
                        // printf("%c", s2[j]);
                    }
                    --j;
                }
                else {
                    for (int k = s1[i - 1] - 1; k >= toupper(s1[i + 1]) + 1; --k, ++j) {
                        s2[j] = k;
                        // printf("%c", s2[j]);
                    }
                    --j;
                }
            }
            else if (isnumber(s1[i - 1]) && isnumber(s1[i + 1])) {
                if (s1[i - 1] <= s1[i + 1]) {
                    for (int k = s1[i - 1] + 1; k <= s1[i + 1] - 1; ++k, ++j) {
                        s2[j] = k;
                        // printf("%c", s2[j]);
                    }
                    --j;
                }
                else {
                    for (int k = s1[i - 1] - 1; k >= s1[i + 1] + 1; --k, ++j) {
                        s2[j] = k;
                        // printf("%c", s2[j]);
                    }
                    --j;
                }
            }
            else {
                s2[j] = s1[i];
                // printf("%c", s2[j]);
            }
        }
        else {
            s2[j] = s1[i];
            // printf("%c", s2[j]);
        }
    }
    s2[j] = '\0';
}
