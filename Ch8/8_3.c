#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool digit_seen[10] = { false };
	int digit;
	long scan_num;
	long n;

	printf("Enter a number: ");

	scanf("%ld", &scan_num);

	while (scan_num > 0) {
		n = scan_num;
		while (n > 0) {
			digit = n % 10;
			if (digit_seen[digit])
				goto repeated;
			digit_seen[digit] = true;

			n /= 10;
		}
		getchar();
		scanf("%ld", &scan_num);

	}

	repeated:
	if (n > 0)
		printf("Repeated digit\n");
	else
		printf("No repeated digit\n");

	return 0;
}