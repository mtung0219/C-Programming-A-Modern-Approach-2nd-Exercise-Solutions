#include <stdio.h>

int main(void)
{
	float x, y;

	printf("Enter a value for x: ");
	scanf("%f", &x);

	y = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

	printf("Answer is (using Horner's Rule): ");
	printf("%.2f", y);

	return 0;
}