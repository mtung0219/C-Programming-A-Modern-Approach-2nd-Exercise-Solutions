#include <stdio.h>

int main(void)
{
	int n;
	int i;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	getchar(); //to get past the first enter key
	for (i = 1; i <= n; i++) {
		if (i % 24 == 0) {
			printf("Press Enter to continue...");
			while (getchar() != '\n')
				;
		}
		printf("%10d%10d\n", i, i * i);
	}

	return 0;
}