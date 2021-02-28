#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

//using the linked list implementation of a stack
int main(void)
{
	Stack s1;
	s1 = create();
	char c;
	printf("Enter parentheses and/or braces: ");
	while ((c = getchar()) != '\n')
	{
		if (c == '(' || c == '{')
			push(s1, c);
		else if (c == ')' || c == '}') {
			char pop_c = pop(s1);

			if ((pop_c == '{' && c == ')') || (pop_c == '(' && c == '}')) {
				printf("Parentheses/braces are NOT nested properly\n");
				destroy(s1);
				exit(0);
			}
		}

	}

	//c is \n now
	if (is_empty(s1))
		printf("Parentheses/braces are nested properly\n");
	else
		printf("Parentheses/braces are NOT nested properly\n");

	destroy(s1);
	return 0;
}