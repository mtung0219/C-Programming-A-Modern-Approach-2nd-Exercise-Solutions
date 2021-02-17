#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 20

int main(void)
{
	char str[MAX_SIZE];
	char smallest_word[MAX_SIZE];
	char largest_word[MAX_SIZE];
	bool cont = true;

	printf("Enter word: ");
	scanf("%s", str);

	strcpy(smallest_word, str);
	strcpy(largest_word, str);
	if (strlen(str) == 4)
		cont = false;

	while (cont) {
		printf("Enter word: ");
		scanf("%s", str);
		if (strlen(str) == 4)
			cont = false;
		

		if (strcmp(str, smallest_word) < 0) {
			strcpy(smallest_word, str);
		}

		if (strcmp(str, largest_word) > 0) {
			strcpy(largest_word, str);
		}
	}

	printf("\nSmallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}
