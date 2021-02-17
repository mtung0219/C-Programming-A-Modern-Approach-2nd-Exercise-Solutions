#include <stdio.h>

int main(void)
{
	// apparently 4 if statements are enough?

	int i1, i2, i3, i4;
	int smallest, largest;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &i1, &i2, &i3, &i4);

	if (i1 <= i2 && i1 <= i3 && i1 <= i4)
		smallest = i1;
	else if (i2 <= i1 && i2 <= i3 && i2 <= i4)
		smallest = i2;
	else if (i3 <= i1 && i3 <= i2 && i3 <= i4)
		smallest = i3;
	else
		smallest = i4;

	if (i1 >= i2 && i1 >= i3 && i1 >= i4)
		largest = i1;
	else if (i2 >= i1 && i2 >= i3 && i2 >= i4)
		largest = i2;
	else if (i3 >= i1 && i3 >= i2 && i3 >= i4)
		largest = i3;
	else
		largest = i4;

	printf("Largest: %d\n", largest);
	printf("Smallest: %d\n", smallest);
	return 0;
}