/* Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

main() {
    float celsius, fahr;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius-Fahrenheit Table\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}