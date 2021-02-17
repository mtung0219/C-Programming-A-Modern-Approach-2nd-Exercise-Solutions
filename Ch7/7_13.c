#include <stdio.h>
#include <ctype.h>

int main(void)
{

	int vowel_count;
	int word_len = 0, word_count = 1;
	char c, first_initial;

	printf("Enter a sentence: ");

	while ((c = getchar()) != '\n') {

		if (c == ' ') {
			word_count += 1;
		}
		else {
			word_len += 1;
		}
	}

	printf("Average word length: %.1f", (float) word_len / word_count);
	return 0;
}