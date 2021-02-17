#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int digit_count[10] = {0};
	int digit;
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		//if (digit_seen[digit])
		//	break;
		digit_count[digit] += 1;

		n /= 10;
	}

	printf("Repeated digit(s): ");

	for (int i = 0; i < 10; i++) {
		if (digit_count[i] > 1)
			printf("%d ", i);
	}

	printf("\n");
	return 0;
}