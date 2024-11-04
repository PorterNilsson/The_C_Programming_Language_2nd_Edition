/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types. */

#include <stdio.h>
#include <limits.h>

int main(void) {
	
	/* char */
	printf("\n *** char ***\n");
	printf("Signed Char Max (defined): %d\n", CHAR_MAX);
	signed char computed_signed_char_max = 0;
	while (computed_signed_char_max >= 0) {
		computed_signed_char_max++;
	}
	computed_signed_char_max--;
	printf("Signed Char Max (computed): %d\n", computed_signed_char_max);

	printf("Signed Char Min (defined): %d\n", CHAR_MIN);
	signed char computed_signed_char_min = 0;
	while (computed_signed_char_min <= 0) {
		computed_signed_char_min--;
	}
	computed_signed_char_min++;
	printf("Signed Char Min (computed): %d\n", computed_signed_char_min);

	printf("Unsigned Char Max (defined): %d\n", UCHAR_MAX);
	unsigned char computed_unsigned_char_max = 1;
	while (computed_unsigned_char_max > 0) {
		computed_unsigned_char_max++;
	}
	computed_unsigned_char_max--;
	printf("Unsigned Char Max (computed): %d\n", computed_unsigned_char_max);


	/* short */
	printf("\n*** short ***\n");
	printf("Signed Short Max (defined): %d\n", SHRT_MAX);
	signed short computed_signed_short_max = 0;
	while (computed_signed_short_max >= 0) {
		computed_signed_short_max++;
	}
	computed_signed_short_max--;
	printf("Signed Short Max (computed): %d\n", computed_signed_short_max);

	printf("Signed Short Min (defined): %d\n", SHRT_MIN);
	signed short computed_signed_short_min = 0;
	while (computed_signed_short_min <= 0) {
		computed_signed_short_min--;
	}
	computed_signed_short_min++;
	printf("Signed Short Min (computed): %d\n", computed_signed_short_min);

	printf("Unsigned Short Max (defined): %d\n", USHRT_MAX);
	unsigned short computed_unsigned_short_max = 1;
	while (computed_unsigned_short_max > 0) {
		computed_unsigned_short_max++;
	}
	computed_unsigned_short_max--;
	printf("Unsigned Short Max (computed): %d\n", computed_unsigned_short_max);


	/* int */
	printf("\n*** int ***\n");
	printf("Signed Int Max (defined): %d\n", INT_MAX);
	signed int computed_signed_int_max = 0;
	while (computed_signed_int_max >= 0) {
		computed_signed_int_max++;
	}
	computed_signed_int_max--;
	printf("Signed Int Max (computed): %d\n", computed_signed_int_max);

	printf("Signed Int Min (defined): %d\n", INT_MIN);
	signed int computed_signed_int_min = 0;
	while (computed_signed_int_min <= 0) {
		computed_signed_int_min--;
	}
	computed_signed_int_min++;
	printf("Signed Int Min (computed): %d\n", computed_signed_int_min);

	printf("Unsigned Int Max (defined): %u\n", UINT_MAX);
	unsigned int computed_unsigned_int_max = 1;
	while (computed_unsigned_int_max > 0) {
		computed_unsigned_int_max++;
	}
	computed_unsigned_int_max--;
	printf("Unsigned Int Max (computed): %u\n", computed_unsigned_int_max);


	/* long */
	printf("\n*** long ***\n");
	printf("Signed Long Max (defined): %ld\n", LONG_MAX);
	signed long computed_signed_long_max = 0;
	while (computed_signed_long_max >= 0) {
		computed_signed_long_max = computed_signed_long_max + 0xffffffffffff;
	}
	computed_signed_long_max = computed_signed_long_max - 0xffffffffffff;
	while (computed_signed_long_max >= 0) {
		computed_signed_long_max++;
	}
	computed_signed_long_max--;
	printf("Signed Long Max (computed): %ld\n", computed_signed_long_max);

	printf("Signed Long Min (defined): %ld\n", LONG_MIN);
	signed long computed_signed_long_min = 0;
	while (computed_signed_long_min <= 0) {
		computed_signed_long_min = computed_signed_long_min - 0xffffffffffff;
	}
	computed_signed_long_min = computed_signed_long_min + 0xffffffffffff;
	/* Last working HERE TODO */
	printf("Signed Long Min (computed): %ld\n", computed_signed_long_min);

	printf("Unsigned Long Max (defined): %lu\n", ULONG_MAX);
	unsigned long computed_unsigned_long_max = 1;
	while (computed_unsigned_long_max > 0) {
		computed_unsigned_long_max = computed_unsigned_long_max + 0xffffffffffff;
	}
	computed_unsigned_long_max = computed_unsigned_long_max - 0xffffffffffff;
	printf("Unsigned Long Max (computed): %lu\n", computed_unsigned_long_max);

	return 0;
}
