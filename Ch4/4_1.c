#include <stdio.h>

int main(void)
{
	int num;

	printf("Enter a two digit nmber: ");
	scanf("%2d", &num);

	printf("The reversal is: %d%d\n", num % 10, num / 10);

	return 0;
}