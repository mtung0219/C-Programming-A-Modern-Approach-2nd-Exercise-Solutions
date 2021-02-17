#include <stdio.h>


#define SIZE 100

int main(void)
{
	int msg[SIZE] = { ' ' };
	int counter = 0;
	char c;
	printf("Enter a message: ");

	while ((c = getchar()) != '\n') {
		msg[counter] = c;
		counter++;
	}

	printf("Reversal is: ");

	int* p;

	//array name used as pointer
	for (p = msg + counter - 1; p >= msg; p--) {
		printf("%c", *p);
	}

	printf("\n");
	return 0;
}