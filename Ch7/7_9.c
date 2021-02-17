#include <stdio.h>
#include <ctype.h>

int main(void)
{

	int hour, min;
	_Bool is_pm;
	char c;

	printf("Enter a 12-hour time: ");
	scanf("%d:%d ", &hour, &min);

	while ((c = getchar()) != '\n') {
		c = toupper(c);

		if (c == 'P')
			is_pm = 1;
		if (c == 'A')
			is_pm = 0;
	}

	if (is_pm && hour != 12)
		hour += 12;
	else if (!is_pm && hour == 12)
		hour -= 12;

	printf("Equivalent 24-hour time: %d:%2.2d\n", hour, min);
	return 0;
}