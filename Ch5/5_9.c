#include <stdio.h>

int main(void)
{
	int first_month, first_date, first_year;
	int sec_month, sec_date, sec_year;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &first_month, &first_date, &first_year);
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &sec_month, &sec_date, &sec_year);

	if (first_year > sec_year)
		printf("%d/%d/%2.2d is earlier than %d/%d/%2.2d\n", sec_month, sec_date, sec_year, first_month, first_date, first_year);
	else if (sec_year > first_year)
		printf("%d/%d/%2.2d is earlier than %d/%d/%2.2d\n", first_month, first_date, first_year, sec_month, sec_date, sec_year);
	else if (first_month > sec_month)
		printf("%d/%d/%2.2d is earlier than %d/%d/%2.2d\n", sec_month, sec_date, sec_year, first_month, first_date, first_year);
	else if (sec_month > first_month)
		printf("%d/%d/%2.2d is earlier than %d/%d/%2.2d\n", first_month, first_date, first_year, sec_month, sec_date, sec_year);
	else if (first_date > sec_date)
		printf("%d/%d/%2.2d is earlier than %d/%d/%2.2d\n", sec_month, sec_date, sec_year, first_month, first_date, first_year);
	else if (sec_date > first_date)
		printf("%d/%d/%2.2d is earlier than %d/%d/%2.2d\n", first_month, first_date, first_year, sec_month, sec_date, sec_year);
	else
		printf("The two dates are the same.\n");

	return 0;
}