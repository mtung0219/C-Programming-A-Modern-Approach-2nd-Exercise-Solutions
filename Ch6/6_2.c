#include <stdio.h>

//Euclid's algorithm for finding GCD of two integers
int main(void)
{
	int m, n, rem;

	printf("Enter two integers: ");
	scanf("%d %d", &m, &n);

	//make sure m is always >= n
	if (m < n) {
		int temp;
		temp = n;
		n = m;
		m = temp;
	}

	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}

	printf("Greatest common divisor: %d\n", m);

	return 0;
}