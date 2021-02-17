#include <stdio.h>

int main(void)
{
	float amount, taxed_amount;

	printf("Enter an amount: ");
	scanf("%f", &amount);

	printf("With tax added: ");
	taxed_amount = amount * 1.05f;
	printf("%.2f", taxed_amount);
	return 0;
}