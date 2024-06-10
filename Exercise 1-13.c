/* Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

#define MAX_WORD_LENGTH 16
#define IN 1
#define OUT 0

main() {
    int c, state, word_length;
    int word_frequencies[MAX_WORD_LENGTH];

    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        word_frequencies[i] = 0;
    }

    state = OUT;
    word_length = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                ++word_frequencies[word_length - 1]; /* Maps word length 1 to index 0 */
                word_length = 0;
                state = OUT;
            }
        }
        else {
            state = IN;
        }

        if (state == IN) {
            ++word_length;
        }
    }
    if (state == IN) {
        ++word_frequencies[word_length - 1]; /* Addresses the case where the word is at the end of the file with no newline. */
    }

    printf("Horizontal Histogram of Word Frequencies\n");
    for (int i = 1; i < MAX_WORD_LENGTH + 1; ++i) { /* Histogram running from 1 -> Max Word Length (not including 0) */
        printf("%2d | ", i);
        for (int j = 0; j < word_frequencies[i - 1]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }

    printf("Vertical Histogram of Word Frequencies\n");
    
}