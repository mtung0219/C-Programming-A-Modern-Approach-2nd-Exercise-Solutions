#include <stdio.h>


void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	int m, n, rem;

	m = numerator;
	n = denominator;
	//calculating GCD, which is m
	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}

	*reduced_numerator = numerator / m;
	*reduced_denominator = denominator / m;

}


int main(void)
{
	int m, n;
	int reduced_numerator, reduced_denominator;

	//assumes m < n
	printf("Enter a fraction: ");
	scanf("%d/%d", &m, &n);

	reduce(m, n, &reduced_numerator, &reduced_denominator);

	printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

	return 0;
}