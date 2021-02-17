#include <stdio.h>
#include <ctype.h>

int main(void)
{

	char c, first_initial;
	char last_name[20] = { ' ' };
	int counter = 0;

	printf("Enter a first and last name: ");

	first_initial = getchar();
	while (getchar() != ' ')
		;

	//put last name into array
	while ((c = getchar()) != '\n') {
		last_name[counter] = c;
		counter++;
	}

	printf("You entered the name: ");

	for (int i = 0; i < counter; i++) {
		printf("%c", last_name[i]);
	}

	printf(", %c.", first_initial);

	return 0;
}