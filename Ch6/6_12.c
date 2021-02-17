#include <stdio.h>

int main(void)
{
	int n;
	float ep;
	float approx = 1.0f;
	float factorial = 1.0f;

	printf("Enter episilon (terms must be larger than): ");
	scanf("%f", &ep);


	int i = 1;
	for (;;) {
		factorial *= i;

		if ((1.0f / factorial) < ep)
			break;
		approx += 1.0f / factorial;

		i++;
	}

	printf("The approximate value of e is %.10f\n", approx);

	return 0;
}