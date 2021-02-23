#include <stdio.h>
#include <stdlib.h>

#define DOUBLE(x) 2*x
#define FIXED_DOUBLE(x) (2*(x))

int main(void)
{

	printf("value of DOUBLE(1+2) is %d\n", DOUBLE(1 + 2));
	printf("value of 4/DOUBLE(2)) is %d\n", 4/DOUBLE(2));

	printf("FIXED value of DOUBLE(1+2) is %d\n", FIXED_DOUBLE(1 + 2));
	printf("FIXED value of 4/DOUBLE(2)) is %d\n", 4 / FIXED_DOUBLE(2));

	return 0;
}