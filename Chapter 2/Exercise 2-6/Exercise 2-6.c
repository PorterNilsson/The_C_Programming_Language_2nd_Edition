/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
position p set to the rightmost n bits of y, leaving the other bits unchanged. */

#include <stdio.h>

int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);

int main(void) {

    printf("%d\n", setbits(0, 7, 6, 65511));

    return 0;
}

int setbits(unsigned int x, uns