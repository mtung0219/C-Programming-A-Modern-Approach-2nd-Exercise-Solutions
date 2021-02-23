#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DISP(f,x) (printf("sqrt(%g) = %g\n", (x), (f(x))))

int main(void)
{
	DISP(sqrt, 3.0);
	DISP(sqrt, 9.0);
	return 0;
}