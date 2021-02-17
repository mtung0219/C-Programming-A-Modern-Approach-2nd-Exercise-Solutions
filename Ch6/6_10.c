#include <stdio.h>

int main(void)
{
	int month, date, year;
	int earliest_month, earliest_date, earliest_year;
	_Bool update;

	// initialize earliest date to something huge
	earliest_year = 99999;
	earliest_month = 99999;
	earliest_date = 99999;

	for (;;) {
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d/%d/%d", &month, &date, &year);

		update = 0;

		if (month == 0 && date == 0 && year == 0)
			break;

		if (year > earliest_year)
			continue;
		else if (earliest_year > year)
			update = 1;
		else if (month > earliest_month)
			continue;
		else if (earliest_month > month)
			update = 1;
		else if (date > earliest_date)
			continue;
		else if (earliest_date > date)
			update = 1;

		if (update) {
			earliest_year = year;
			earliest_month = month;
			earliest_date = date;
		}

	}

	printf("%d/%d/%2.2d is the earliest date\n", earliest_month, earliest_date, earliest_year);

	return 0;
}