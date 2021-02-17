#include <stdio.h>

int main(void)
{
	int num;
	char* tens[] = { "twenty", "thirty","forty","fifty","sixty","seventy","eighty","ninety" };
	char* teens[] = { "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
	char* ones[] = { "one","two","three","four","five","six","seven","eight","nine", "ten" };

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	int tens_digit = num / 10;
	int ones_digit = num % 10;

	printf("You entered the number ");

	if (num >= 11 && num <= 19)
		printf("%s", teens[ones_digit - 1]);
	else if (num <= 10)
		printf("%s", ones[ones_digit - 1]);
	else if (ones_digit != 0)
		printf("%s-%s", tens[tens_digit - 2], ones[ones_digit - 1]);
	else
		printf("%s", tens[tens_digit - 2]);

	printf(".\n");
	return 0;
}