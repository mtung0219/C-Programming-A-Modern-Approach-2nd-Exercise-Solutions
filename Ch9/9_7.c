#include <stdio.h>
#include <ctype.h>


int power(int x, int n) 
{
	if (n == 0)
		return 1;

	if (n % 2 == 0) //even
		return power(x, n / 2) * power(x, n / 2);
	else // odd
		return x * power(x, n - 1);
}

int main(void)
{

	int x, n;

	printf("Enter a value for x: ");
	scanf("%d", &x);

	printf("Enter a value for n: ");
	scanf("%d", &n);

	printf("x^n is : %d\n", power(x,n));

	return 0;
}