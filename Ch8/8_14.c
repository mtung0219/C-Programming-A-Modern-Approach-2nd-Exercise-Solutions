#include <stdio.h>
#include <ctype.h>

int main(void)
{

	char c, first_initial;
	char sentence[2000] = { ' ' };
	int counter = 0, marker;

	printf("Enter a sentence: ");

	//put sentence into array
	while (((c = getchar()) != '.') && (c != '?') && (c != '!')) {
		sentence[counter] = c;
		counter++;
	}

	// put terminating character
	sentence[counter] = c;

	int i = counter - 1;
	marker = counter;
	printf("Reversal of sentence:");
	for (int i = counter-1; i >= 0; i--) {

		if (sentence[i] == ' ' || i == 0) {

			if (i == 0) //since first word has no space before it
				printf(" ");

			//print next last word
			for (int j = i; j < marker; j++) {
				printf("%c", sentence[j]);
			}
			marker = i;
		}
	}

	//print terminating character
	printf("%c\n", sentence[counter]);
	return 0;
}