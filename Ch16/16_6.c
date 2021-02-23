#include <stdio.h>
struct date {
	int year;
	int month;
	int date;
};
int compare_dates(struct date d1, struct date d2);
int main(void)
{
	int first_month, first_date, first_year;
	int sec_month, sec_date, sec_year;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &first_month, &first_date, &first_year);

	struct date d1 = { first_year, first_month,first_date };
	
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &sec_month, &sec_date, &sec_year);
	struct date d2 = { sec_year, sec_month,sec_date };

	int comp = compare_dates(d1, d2);

	if (comp == 1)
		printf("%d/%d/%2.2d is earlier than %d/%d/%2.2d\n", first_month, first_date, first_year, sec_month, sec_date, sec_year);
	else
		printf("%d/%d/%2.2d is earlier than %d/%d/%2.2d\n", sec_month, sec_date, sec_year, first_month, first_date, first_year);

	return 0;
}

int compare_dates(struct date d1, struct date d2)
{
	// returns 0 if d1 is later, 1 if d2 is later
	if (d1.year > d2.year)
		return 0;
	if (d2.year > d1.year)
		return 1;
	if (d1.month > d2.month)
		return 0;
	if (d2.month > d1.month)
		return 1;
	if (d1.date > d2.date)
		return 0;
	return 1;
}