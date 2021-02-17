#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 100

int main(void)
{
	int msg[SIZE] = { ' ' };
	int counter = 0;
	char c;
	printf("Enter a message: ");

	while ((c = getchar()) != '\n') {
		c = toupper(c);
		if (c >= 'A' && c <= 'Z') {
			msg[counter] = c;
			counter++;
		}
	}

	printf("Reversal is: ");

	int* p1;
	int* p2;

	p1 = msg;
	p2 = msg + counter - 1;

	while (p1 < p2) {

		if (*p1 != *p2) {
			printf("Not palindrome\n");
			exit(0);
		}

		p1++;
		p2--;
	}
	printf("Is Palindrome\n");
	return 0;
}