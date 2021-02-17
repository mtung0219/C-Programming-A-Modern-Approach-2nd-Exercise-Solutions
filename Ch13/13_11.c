#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 200

double compute_average_word_length(const char* sentence)
{
	int word_count = 1;
	int word_len = 0;

	while (*sentence != '\0') {

		if (*sentence == ' ')
			word_count++;
		else
			word_len++;

		sentence++;
	}
	return (float)word_len / word_count;
}



int main(void)
{
	char sentence[MAX_LENGTH + 1];

	printf("Enter a sentence: ");

	gets(sentence);

	printf("Average word length: %.1f", compute_average_word_length(&sentence[0]));

	return 0;
}