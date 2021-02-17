#include <stdio.h>

int main(void)
{
	char c;
	char phone_num[15] = {' '};
	int counter = 0;

	printf("Enter phone number: ");

	while ((c = getchar()) != '\n') {
		if (c <= 'C' && c >= 'A')
			c = '2';
		else if (c <= 'F' && c >= 'D')
			c = '3';
		else if (c <= 'I' && c >= 'G')
			c = '4';
		else if (c <= 'L' && c >= 'J')
			c = '5';
		else if (c <= 'O' && c >= 'M')
			c = '6';
		else if (c <= 'S' && c >= 'P')
			c = '7';
		else if (c <= 'V' && c >= 'T')
			c = '8';
		else if (c <= 'Y' && c >= 'W')
			c = '9';

		phone_num[counter] = c;
		counter++;
	}

	printf("In numeric form: ");

	for (int i = 0; i < counter; i++) {
		printf("%c", phone_num[i]);
	}
	printf("\n");

	return 0;
}