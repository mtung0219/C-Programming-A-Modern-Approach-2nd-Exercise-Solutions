#include <stdio.h>
#include <ctype.h>

int main(void)
{

	char c;
	int count[26] = { 0 };
	int counter = 0;
	int shift_amount;

	printf("Enter first word: ");

	while ((c = getchar()) != '\n') {
		if (isalpha(c)) {
			c = tolower(c);
			count[c - 'a'] += 1;
		}
	}

	printf("Enter second word: ");

	while ((c = getchar()) != '\n') {
		if (isalpha(c)) {
			c = tolower(c);
			count[c - 'a'] -= 1;
		}
	}
	int i = 25;
	for (i = 25; i >= 0; i--) {
		if (count[i] != 0)
			break;
	}

	if (i > 0)
		printf("The words are not anagrams.\n");
	else
		printf("The words are anagrams.\n");

	return 0;
}