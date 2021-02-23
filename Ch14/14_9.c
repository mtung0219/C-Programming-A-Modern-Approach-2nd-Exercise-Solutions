#include <stdio.h>

#define CHECK(x,y,n) ((x) <= ((n)-1) && (y) <= ((n)-1) && (x) >= 0 && (y) >= 0 ? 1:0)

#define MEDIAN(x,y,z) (((x < y && y < z) || (z < y && y < x))? y: \
((y < x && x < z) || (z < x && x < y))? x :z)

#define POLYNOMIAL(x) (3*(x)*(x)*(x)*(x)*(x) + 2 * (x)*(x)*(x)*(x) - 5*(x)*(x)*(x) - (x)*(x) + 7 * (x) - 6)

int main(void)
{
	
	printf("%d\n", CHECK(5,6,10));
	printf("%d\n", MEDIAN(5, 3, 10));
	printf("%d\n", POLYNOMIAL(1));
}