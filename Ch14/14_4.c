#include <stdio.h>
#include <stdlib.h>

#define AVG(x,y) (x-y)/2
#define AREA(x,y) (x)*(y)


#define FIXED_AVG(x,y) ((x+y)/2)
#define FIXED_AREA(x,y) ((x)*(y))

int main(void)
{

	printf("value of 1.5/AVG(1,2) is %f\n", 1.5/AVG(1,2));
	printf("value of 4/AREA(2,2) is %d\n", 4 / AREA(2, 2));

	printf("FIXED value of 1.5/AVG(1,2) is %f\n", 1.5 / FIXED_AVG(1, 2));
	printf("FIXED value of 4/AREA(2,2) is %d\n", 4 / FIXED_AREA(2, 2));

	return 0;
}