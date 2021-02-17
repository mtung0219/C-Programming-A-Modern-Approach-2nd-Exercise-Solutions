#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
	char* months[] = { "January", "February", "March", "April",
	"May", "June", "July", "August", "September", "October",
	"November","December" };

	int month, date, year;

	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &date, &year);


	printf("You entered the date %s %d, %d\n", months[month-1], date, year);
}