#include <stdio.h>

int main(void)
{
	float income;

	printf("Enter taxable income: ");
	scanf("%f", &income);

	if (income <= 750)
		printf("%.2f\n", 0.01f * income);
	else if (income <= 2250)
		printf("%.2f\n", 0.02f * (income - 750.00f) + 7.50f);
	else if (income <= 3750)
		printf("%.2f\n", 0.03f * (income - 2250.00f) + 37.50f);
	else if (income <= 5250)
		printf("%.2f\n", 0.04f * (income - 3750.00f) + 82.50f);
	else if (income <= 7000)
		printf("%.2f\n", 0.05f * (income - 5250.00f) + 142.50f);
	else
		printf("%.2f\n", 0.06f * (income - 7000.00f) + 230.00f);

	return 0;
}