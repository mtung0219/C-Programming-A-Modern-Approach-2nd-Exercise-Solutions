#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
	int x;
	double y, old_y, guess, avg;
	old_y = 0;

	printf("Enter a positive number: ");
	scanf("%d", &x);

	y = 1;

	while (fabs(old_y - y) > (0.00001 * y)) {
		guess = x / y;

		avg = (y + guess) / 2;
		old_y = y;
		y = avg;
	}
	printf("Square root: %f\n", y);

	return 0;
}