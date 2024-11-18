/* Exercise  2-7.  Write  a  function  invert(x,p,n)  that  returns  x  with  the  n  bits  that  begin  at  
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. */

#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

int main(void) {
	
	printf("%d\n", invert(80, 6, 3));

	return 0;
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n) {
	
	/* Assume p is position from the right (zero-indexed) */
	
	unsigned int mask = (~((~0) << (n))) << (p + 1 - n); 
	// printf("Mask: %u\n", mask);
	unsigned int x_inverted = ~x;
	// printf("X Inverted: %u\n", x_inverted);
	unsigned int mask_inverted = mask & x_inverted;
	
	mask = ~mask;
	x = x & mask;
	x = x | mask_inverted;
	
	return x;
}

