#include <stdio.h>

int main(void)
{
	int num, num_digits;

	printf("Enter a number: ");

	scanf("%d", &num);

	num_digits = 0;
	if (num >= 0 && num <= 9) {
		num_digits = 1;
	}
	else if (num >= 10 && num <= 99) {
		num_digits = 2;
	}
	else if (num >= 100 && num <= 999) {
		num_digits = 3;
	}
	else if (num >= 1000 && num <= 9999) {
		num_digits = 4;
	}
	
	printf("The number %d has %d digits\n", num, num_digits);

	return 0;
}