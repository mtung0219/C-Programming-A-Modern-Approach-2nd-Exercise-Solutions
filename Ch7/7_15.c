#include <stdio.h>
#include <ctype.h>
#include <math.h>

//int type constrained to x <= 31
//long type contrained to x <= 33
//double type constrained to x <= 170, then shows "inf"
int main(void)
{
	typedef double factorial;

	factorial x;
	factorial x_copy;
	factorial fact = 1;

	printf("Enter a positive integer: ");
	scanf("%lf", &x);
	x_copy = x;
	while (x > 0) {
		fact *= x;
		x--;
	}


	printf("Factorial of %f: %f\n", x_copy, fact);

	return 0;
}