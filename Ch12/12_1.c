#include <stdio.h>


#define SIZE 100

int main(void)
{
	int msg[SIZE] = {' '};
	int counter = 0;
	char c;
	printf("Enter a message: ");

	while ((c = getchar()) != '\n') {
		msg[counter] = c;
		counter++;
	}

	printf("Reversal is: ");

	int* p;

	//part (b) version
	for (p = msg + counter - 1; p >= msg; p--) {
		printf("%c", *p);
	}

	// part (a) version
	/*for (int i = counter - 1; i >= 0; i--) {
		printf("%c", msg[i]);
	}*/

	printf("\n");
	return 0;
}