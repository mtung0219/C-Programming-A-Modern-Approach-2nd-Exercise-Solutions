#include <stdio.h>

int main(void)
{
	int m, n, rem, orig_numerator, orig_denominator;

	int new_numer, new_denom;

	//assumes m < n
	printf("Enter a fraction: ");
	scanf("%d/%d", &m, &n);
	
	orig_numerator = m;
	orig_denominator = n;


	//calculating GCD, which is m
	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}

	new_numer = orig_numerator / m;
	new_denom = orig_denominator / m;

	printf("In lowest terms: %d/%d\n", new_numer, new_denom);

	return 0;
}