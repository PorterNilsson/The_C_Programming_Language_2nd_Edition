/* How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any? */

/* 
    Answer: 
    
    To test this program, you would want to throw a variety of edge cases at it.
    It might have issues with punctuation or symbols that might not necessarily be considered "words" (numeric symbols, etc).
*/

/* Original Word Count Program */
#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
        while ((c = getchar()) != EOF) {
            ++nc;
            if (c == '\n')
                ++nl;
            if (c == ' ' || c == '\n' || c == '\t')
                state = OUT;
            else if (state == OUT) {
                state = IN;
            ++nw;
            }
        }
    printf("%d %d %d\n", nl, nw, nc);
} 