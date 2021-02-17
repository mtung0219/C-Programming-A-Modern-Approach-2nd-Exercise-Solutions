#include <stdio.h>
#include <ctype.h>

int main(void)
{

	int vowel_count;
	char c;

	printf("Enter a sentence: ");

	while ((c = getchar()) != '\n') {
		c = toupper(c);

		if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
			vowel_count += 1;
	}

	printf("Your sentence contains %d vowels.\n", vowel_count);
	return 0;
}