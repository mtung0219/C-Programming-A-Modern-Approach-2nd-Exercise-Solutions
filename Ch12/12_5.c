#include <stdio.h>
#include <ctype.h>

int main(void)
{

	char c, first_initial;
	char sentence[2000] = { ' ' };
	int counter = 0;

	printf("Enter a sentence: ");

	//put sentence into array
	while (((c = getchar()) != '.') && (c != '?') && (c != '!')) {
		sentence[counter] = c;
		counter++;
	}

	// put terminating character
	sentence[counter] = c;

	char* p;
	char* q;

	int marker;
	marker = counter;
	printf("Reversal of sentence:");
	//p points to end of sentence, goes backward
	//q points to beginning of each last word, goes forward for duration of word

	for (p = &sentence[0] + counter - 1; p >= &sentence[0]; p--) {

		if (*p == ' ' || p == sentence) {

			if (p == sentence) //since first word has no space before it
				printf(" ");

			//print next last word
			for (q = p; q < sentence + marker; q++) {
				printf("%c", *q);
			}
			marker = (p - &sentence[0]);
		}
	}

	//print terminating character
	printf("%c\n", sentence[counter]);
	return 0;
}