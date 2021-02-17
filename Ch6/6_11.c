#include <stdio.h>

int main(void)
{
	int n;
	float approx = 1.0f;
	float factorial = 1.0f;
	
	printf("Enter number of terms to approximate e: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++, factorial *= i) {
		approx += 1.0f / factorial;
	}

	printf("The approximate value of e is %.5f\n", approx);

	return 0;
}