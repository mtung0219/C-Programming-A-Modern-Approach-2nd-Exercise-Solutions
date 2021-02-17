#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


void read_word(int counts[26]) {
	char c;
	while ((c = getchar()) != '\n') {
		if (isalpha(c)) {
			c = tolower(c);
			counts[c - 'a'] += 1;
		}
	}
}

bool equal_array(int counts1[26], int counts2[26]) {
	int i = 25;
	for (i = 25; i >= 0; i--) {
		if (counts1[i] != counts2[i])
			return false;
	}

	return true;
}
int main(void)
{

	char c;
	int counts1[26] = { 0 };
	int counts2[26] = { 0 };
	int counter = 0;
	int shift_amount;

	printf("Enter first word: ");

	read_word(counts1);

	printf("Enter second word: ");

	read_word(counts2);

	if (equal_array(counts1, counts2) == false)
		printf("The words are not anagrams.\n");
	else
		printf("The words are anagrams.\n");

	return 0;
}