/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
in x. Explain why. Use this observation to write a faster version of bitcount. */

/* Original Function: "count 1 bits in x"

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

*/

#include <stdio.h>

int bitcount(unsigned x);

int main(void) {

    printf("%d\n", bitcount(65534));

    return 0;
}

int bitcount(unsigned x) {

    /* This improved version only requires n iterations where n is the number of ones in the number.

    Essentially, this works because "and-ing" a number with itself minus 1 will cause the only difference 
    between the two numbers to result in a zero after the and operation.

    */

    unsigned b = 0;
    while (x != 0) {
        x &= (x - 1);
        b++;
    }

    return b;
}
