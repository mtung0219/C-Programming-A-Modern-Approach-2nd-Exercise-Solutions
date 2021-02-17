#include <stdio.h>

int main(void)
{
	int month, day, year, item_number;
	float unit_price;

	printf("Enter item number: ");
	scanf("%d", &item_number);

	printf("Enter unit price: ");
	scanf("%f", &unit_price);

	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("Item\t\tUnit\t\t\tPurchase\n\t\tPrice\t\t\tDate\n%-d\t\t$%6.2f\t\t\t%-2.2d/%-2.2d/%-d", 
		item_number, unit_price, month, day, year);

	return 0;
}