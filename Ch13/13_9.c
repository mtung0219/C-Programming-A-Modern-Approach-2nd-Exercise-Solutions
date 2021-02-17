#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

//returns number of vowels in the string pointed to by sentence parameter.
int compute_vowel_count(const char* sentence)
{
	int count = 0;
	char c;
	for (; *sentence != '\0'; sentence++) {
		c = toupper(*sentence);
		if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			count++;
		}
	}
	return count;
}


int main(void)
{
	char sentence[MAX_SIZE + 1];

	printf("Enter a sentence: ");

	gets(sentence);

	printf("Your sentence contains %d vowels.\n", compute_vowel_count(&sentence[0]) );
	return 0;
}