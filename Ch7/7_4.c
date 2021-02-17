#include <stdio.h>

int main(void)
{
	char c;

	printf("Enter phone number: ");
	
	while ((c = getchar()) != '\n') {
		if (c <= 'C' && c >= 'A')
			printf("2");
		else if (c <= 'F' && c >= 'D')
			printf("3");
		else if (c <= 'I' && c >= 'G')
			printf("4");
		else if (c <= 'L' && c >= 'J')
			printf("5");
		else if (c <= 'O' && c >= 'M')
			printf("6");
		else if (c <= 'S' && c >= 'P')
			printf("7");
		else if (c <= 'V' && c >= 'T')
			printf("8");
		else if (c <= 'Y' && c >= 'W')
			printf("9");
		else
			printf("%c", c);
	}

	return 0;
}