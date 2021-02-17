#include <stdio.h>
#include <ctype.h>


int func_calculator(int x) {

	return 3 * x * x * x * x * x
		+ 2 * x * x * x * x 
		- 5 * x * x * x - x * x
		+ 7 * x 
		- 6;
}

int main(void)
{

	long x;

	printf("Enter a value for x: ");
	scanf("%d", &x);

	printf("Answer: %d\n", func_calculator(x));

	return 0;
}