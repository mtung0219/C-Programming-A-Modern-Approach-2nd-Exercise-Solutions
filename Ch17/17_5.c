#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include <string.h>

#define MAX_WORDS 50
#define MSG_LEN 60

int read_line(char str[], int n);
int compare_words(const void *p, const void *q);

int main(void)
{
	char* word_list[MAX_WORDS];
	char msg[MSG_LEN + 1];
	int i;
	int num_input = 0;
	char* user_input[MAX_WORDS];
	for (;;) {
		if (num_input == MAX_WORDS) {
			printf("-- No space left -- \n");
			break;
		}

		printf("Enter a word: ");
		read_line(msg, MSG_LEN);
		if (msg[0] == '\0') {
			qsort(word_list, num_input, sizeof(char *), compare_words);
			
			printf("In sorted order: \n");
			for (int j = 0; j < num_input; j++)
				printf("%s ", word_list[j]);
			//free(*word_list);
			return 0;
		}
		
		i = num_input;
		word_list[i] = malloc(2 * strlen(msg) + 1);
		if (word_list[i] == NULL) {
			printf(" -- NO SPACE TO ALLOCATE -- \n");
			break;
		}
		strcpy(word_list[i], msg);

		num_input++;

	}
	return 0;
}

int compare_words(const void* p, const void* q)
{
	const char* p_char = *(const char**)p;
	const char* q_char = *(const char**)q;

	return strcmp(p_char, q_char);
}