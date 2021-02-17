#include <stdio.h>

int main(void)
{
	int num, two_digit_temp;

	printf("Enter a three digit nmber: ");
	scanf("%3d", &num);

	two_digit_temp = num / 10;
	
	printf("The reversal is: %d%d%d\n", num % 10, two_digit_temp % 10, two_digit_temp / 10);

	return 0;
}