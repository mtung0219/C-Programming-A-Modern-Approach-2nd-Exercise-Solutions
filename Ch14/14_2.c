#include <stdio.h>
#include <stdlib.h>

#define NELEMS(a) ((int) sizeof(a)/sizeof(a[0]))

int main(void)
{
	int test[10] = { 0 };
	char test1[15] = { " " };

	// some test cases below
	printf("array has %d number of elements\n", NELEMS(test));

	printf("array has %d number of elements\n", NELEMS(test1));


}