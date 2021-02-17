#include <stdio.h>

int main(void)
{
	int days, starting_day;

	printf("Enter number of days in month: ");
	scanf("%d", &days);

	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &starting_day);

	for (int j = starting_day-1; j > 0; j--) {
		printf("     ");
	}


	for (int i = 1; i <= days; i++) {
		printf("%5d", i);

		if (starting_day == 7) {
			printf("\n");
			starting_day = 0;
		}

		starting_day++;
	}


	return 0;
}