#include <stdio.h>
#include <ctype.h>


#define MAX_SENTENCE_SIZE 30
#define MAX_WORD_SIZE 20
int main(void)
{
	char words[MAX_SENTENCE_SIZE][MAX_WORD_SIZE + 1] = { ' ' };
	char c;
	char terminating_char;
	int counter = 0,word_counter = 0;

	printf("Enter a sentence: ");

	while (((c = getchar()) != '.') && (c != '?') && (c != '!')) {
		if (c == ' ') {
			words[word_counter][counter] = '\0';
			word_counter++;
			counter=0;
		}
		else {
			words[word_counter][counter] = c;
			counter++;
		}
	}
	words[word_counter][counter] = '\0';
	terminating_char = c;

	for (int i = word_counter; i >= 0; i--) {
		int j = 0;
		while (words[i][j] != '\0') {
			printf("%c", words[i][j]);
			j++;
		}
		printf(" ");
	}

	//print terminating character
	printf("%c\n", terminating_char);
	return 0;
}