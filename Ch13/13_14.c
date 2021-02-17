#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_SIZE 100

bool are_anagrams(const char* word1, const char* word2)
{
	char c;
	int count[26] = { 0 };

	while (*word1 != '\0') {
		c = tolower(*word1);
		count[c - 'a'] += 1;
		word1++;
	}
	while (*word2 != '\0') {
		c = tolower(*word2);
		count[c - 'a'] -= 1;
		word2++;
	}

	int i = 25;
	for (i = 25; i >= 0; i--) {
		if (count[i] != 0)
			return false;
	}
	return true;
}

int main(void)
{
	char word1[MAX_WORD_SIZE+1];
	char word2[MAX_WORD_SIZE+1];

	printf("Enter first word: ");
	gets(word1);

	printf("Enter second word: ");
	gets(word2);

	bool yes = are_anagrams(&word1[0], &word2[0]);

	if (yes)
		printf("The words are anagrams.\n");
	else
		printf("The words are NOT anagrams.\n");

	return 0;
}