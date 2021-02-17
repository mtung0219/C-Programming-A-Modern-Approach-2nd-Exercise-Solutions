#include <stdio.h>
#include <ctype.h>

#define NUM_RATES ( (int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
	
	int n;
	n = 50; // not sure how to allocate array for this problem?
	char c;
	char char_array[n];

	int counter = 0;

	printf("Enter message: ");
	
	while ((c = getchar()) != '\n') {
		c = toupper(c);

		if (c == 'A')
			c = '4';
		if (c == 'B')
			c = '8';
		if (c == 'E')
			c = '3';
		if (c == 'I')
			c = '1';
		if (c == 'O')
			c = '0';
		if (c == 'S')
			c = '5';

		char_array[counter] = c;
		counter++;
	}

	printf("In B1FF-speak: ");

	for (int j = 0; j < counter; j++) {
		printf("%c", char_array[j]);
	}

	printf("!!!!!!!!!!!!\n");
	return 0;
}