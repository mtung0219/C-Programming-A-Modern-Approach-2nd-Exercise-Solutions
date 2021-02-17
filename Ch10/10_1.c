#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

bool stack_overflow = false;
bool stack_underflow = false;

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(char c)
{
	if (is_full())
		stack_overflow = true;
		//stack_overflow();
	else
		contents[top++] = c;
}

char pop(void)
{
	if (is_empty())
		stack_underflow = true;
		//stack_underflow();
	else
		return contents[--top];
}

int main(void)
{
	char c;
	printf("Enter parentheses and/or braces: ");
	while ((c = getchar()) != '\n')
	{
		if (c == '(' || c == '{')
			push(c);
		else if (c == ')' || c == '}') {
			char pop_c = pop();

			if ((pop_c == '{' && c == ')') || (pop_c == '(' && c == '}')) {
				printf("Parentheses/braces are NOT nested properly\n");
				exit(0);
			}
		}

		if (stack_overflow) {
			printf("Stack overflow\n");
			exit(0);
		}

		if (stack_underflow) {
			printf("Parentheses/braces are NOT nested properly\n");
			exit(0);
		}

	}

	//c is \n now
	if (is_empty())
		printf("Parentheses/braces are nested properly\n");
	else
		printf("Parentheses/braces are NOT nested properly\n");

	return 0;
}