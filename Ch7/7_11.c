#include <stdio.h>
#include <ctype.h>

int main(void)
{

	int vowel_count;
	char c, first_initial;

	printf("Enter a first and last name: ");
	
	first_initial = getchar();
	while (getchar() != ' ')
		;

	while ((c = getchar()) != '\n') {
		printf("%c", c);
	}

	printf(", %c.", first_initial);

	return 0;
}