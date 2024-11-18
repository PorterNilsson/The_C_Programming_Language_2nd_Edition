/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated 
to the right by n positions. */

#include <stdio.h>
#include <limits.h>

int rightrot(int x, unsigned int n);

int main(void) {

    printf("%d\n", rightrot(7, 13));
    
    return 0;
}

int rightrot(int x, unsigned int n) {

    for (int i = 0; i < n; i++) {
        unsigned int mask = 0;
        mask = ~((~mask) << 1) & x;
        // printf("X: %d\n", x);
        // printf("Mask: %u\n", mask);
        x =  x >> 1;
        if (x < 0 && mask == 0) {
            x = x + INT_MAX + 1;
        }
        else if (x >= 0 && mask == 1) {
            x = x + INT_MIN;
        }
    }

    return x;
}
