#include <stdio.h>

int main(void)
{
	int hour, min;
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &min);

	if (hour == 12) {
		printf("Equivalent 12-hour time: %d:%2.2d PM\n", hour, min);
	}
	else if (hour > 12) {
		hour -= 12;
		printf("Equivalent 12-hour time: %d:%2.2d PM\n", hour, min);
	}
	else {
		printf("Equivalent 12-hour time: %d:%2.2d AM\n", hour, min);
	}

	return 0;
}