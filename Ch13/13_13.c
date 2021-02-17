#include <stdio.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 200

void encrypt(char* message, int shift)
{
	while (*message != '\0') {
		if (*message <= 'Z' && *message >= 'A') {
			*message = ((*message - 'A') + shift) % 26 + 'A';
		}
		else if (*message <= 'z' && *message >= 'a') {
			*message = ((*message - 'a') + shift) % 26 + 'a';
		}
		message++;
	}
}


int main(void)
{
	char sentence[MAX_MESSAGE_LENGTH];
	char c;
	int counter = 0;
	int shift_amount;

	printf("Enter message to be encrypted: ");
	gets(sentence);

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift_amount);


	encrypt(&sentence[0], shift_amount);
	printf("Encrypted message: %s\n", sentence);

	return 0;
}