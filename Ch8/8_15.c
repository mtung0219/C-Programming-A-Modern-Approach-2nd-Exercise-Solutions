#include <stdio.h>
#include <ctype.h>

int main(void)
{

	char c;
	char sentence[80] = { ' ' };
	int counter = 0;
	int shift_amount;

	printf("Enter message to be encrypted: ");

	//put sentence into array
	while ( (c = getchar()) != '\n') {
		sentence[counter] = c;
		counter++;
	}

	printf("Enter shift amount (1-25): ");

	scanf("%d", &shift_amount);

	printf("Encrypted message: ");
	
	for (int i = 0; i < counter; i++) {
		char n = sentence[i];

		//upper case letter
		if (n <= 'Z' && n >= 'A') {
			n = ((n - 'A') + shift_amount) % 26 + 'A';
		}
		else if (n <= 'z' && n >= 'a') {
			n = ((n - 'a') + shift_amount) % 26 + 'a';
		}

		printf("%c", n);

	}

	printf("\n");

	return 0;
}