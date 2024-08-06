/* Experiment to find out what happens when prints's argument string contains
\c, where c is some character not listed above. */

#include <stdio.h>

main()
{
    printf("\chello, world\n");
} 

/* There's a compiler warning about an unknown escape sequence. Running the program prints "chello, world" */