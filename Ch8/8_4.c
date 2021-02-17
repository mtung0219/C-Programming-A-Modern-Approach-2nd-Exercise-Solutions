#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 }; //digits
	bool digit_seen[(int) (sizeof(a) / sizeof(a[0]))] = { false };
	int digit;
	long n;

	printf("Enter a number: ");

	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit])
			break;
		digit_seen[digit] = true;

		n /= 10;
	}

	if (n > 0)
		printf("Repeated digit\n");
	else
		printf("No repeated digit\n");

	return 0;
}