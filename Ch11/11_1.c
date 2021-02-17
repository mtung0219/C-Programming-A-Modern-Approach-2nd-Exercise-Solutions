#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
	int amount_left;

	*twenties = dollars / 20;

	amount_left = dollars % 20;

	*tens = amount_left / 10;

	amount_left = amount_left % 10;

	*fives=amount_left / 5;

	amount_left = amount_left % 5;

	*ones = amount_left;

	return;
}


int main(void)
{
	int dollar_amount, amount_left;
	int twenties, tens, fives, ones;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollar_amount);

	pay_amount(dollar_amount, &twenties, &tens, &fives, &ones);

	printf("$20 bills: %d\n", twenties);
	printf("$10 bills: %d\n", tens);
	printf("$5 bills: %d\n", fives);
	printf("$1 bills: %d\n", ones);

	return 0;
}