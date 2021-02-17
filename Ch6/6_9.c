#include <stdio.h>

int main(void)
{
	float loan_amount, interest_rate, monthly_payment;

	int num_payments;

	printf("Enter number of payments: ");
	scanf("%d", &num_payments);

	printf("Enter amount of loan: ");
	scanf("%f", &loan_amount);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	for (int i = 0; i < num_payments; i++) {

		loan_amount = loan_amount - monthly_payment + loan_amount * interest_rate / 100.0f / 12.0f;
		printf("Balance remaining after payment %d: %.2f\n", i+1, loan_amount);
	}

	return 0;
}