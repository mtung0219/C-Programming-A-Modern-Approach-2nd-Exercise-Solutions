#include <stdio.h>

int main(void)
{
	int dollar_amount, amount_left;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollar_amount);

	printf("$20 bills: %d\n", dollar_amount / 20);

	amount_left = dollar_amount % 20;

	printf("$10 bills: %d\n", amount_left / 10);

	amount_left = amount_left % 10;

	printf("$5 bills: %d\n", amount_left / 5);

	amount_left = amount_left % 5;

	printf("$1 bills: %d\n", amount_left);

	return 0;
}