#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stackADT.h"

int main(void)
{
	Stack s1;
	s1 = create();
	int i1, i2;
	char c;
	int digit = 0;
	bool cont = true;

	while (cont) {
		printf("Enter an RPN expression: ");
		while ((c = getchar()) != '\n')
		{
			if (c >= '0' && c <= '9')
				digit = c - '0';

			else if (c == ' ') {
				if (digit < 10) {
					push(s1, digit);
					digit = 99;
				}
			}

			else if (c == '+') {
				i1 = pop(s1);
				i2 = pop(s1);
				push(s1, i2 + i1);
			}
			else if (c == '-') {
				i1 = pop(s1);
				i2 = pop(s1);
				push(s1, i2 - i1);
			}
			else if (c == '*') {
				i1 = pop(s1);
				i2 = pop(s1);
				push(s1, i2 * i1);
			}
			else if (c == '/') {
				i1 = pop(s1);
				i2 = pop(s1);
				int result = i2 / i1;
				push(s1, result);
			}

			else if (c == '=') {
				i1 = pop(s1);
				make_empty(s1);
				break;
			}
			else {
				cont = false;
				destroy(s1);
				exit(0);
			}
		}

		printf("Value of expression: %d\n", i1);

		getchar();
	}
	destroy(s1);
	return 0;
}