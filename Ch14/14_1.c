#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CUBE(x) ((x) * (x) * (x))
#define DIV_FOUR_REM(x) ((x) % 4)
#define PROD_LESS_THAN_HUNDRED(x,y) ((x)*(y) < 100 ? 1 : 0)

int main(void)
{
	// some test cases below
	printf("2 cubed is %d\n", CUBE(2));
	printf("-2 cubed is %d\n", CUBE(-2));

	printf("5 div 4 remainder is %d\n", DIV_FOUR_REM(5));
	printf("3 div 4 remainder is %d\n", DIV_FOUR_REM(3));

	printf("should be 1: %d\n", PROD_LESS_THAN_HUNDRED(10,9));
	printf("should be 0: %d\n", PROD_LESS_THAN_HUNDRED(10, 11));


}