#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
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

void push(int c)
{
	if (is_full())
		stack_overflow = true;
	//stack_overflow();
	else
		contents[top++] = c;
}

int pop(void)
{
	if (is_empty())
		stack_underflow = true;
	//stack_underflow();
	else
		return contents[--top];
}

int main(void)
{
	int i1, i2;
	char c;
	int digit=0;
	bool cont = true;

	while (cont) {
		printf("Enter an RPN expression: ");
		while ((c = getchar()) != '\n')
		{
			if (c >= '0' && c <= '9')
				digit = c - '0';

			else if (c == ' ') {
				if (digit < 10) {
					push(digit);
					digit = 99;
				}
			}

			else if (c == '+') {
				i1 = pop();
				i2 = pop();
				push(i2 + i1);
			}
			else if (c == '-') {
				i1 = pop();
				i2 = pop();
				push(i2 - i1);
			}
			else if (c == '*') {
				i1 = pop();
				i2 = pop();
				push(i2 * i1);
			}
			else if (c == '/') {
				i1 = pop();
				i2 = pop();
				int result = i2 / i1;
				push(result);
			}

			else if (c == '=') {
				i1 = pop();
				make_empty();
				break;
			}
			else {
				cont = false;
				exit(0);
			}
			if (stack_overflow) {
				printf("Expression is too complex.\n");
				exit(0);
			}

			if (stack_underflow) {
				printf("Not enough operands in expression.\n");
				exit(0);
			}
		}

		printf("Value of expression: %d\n", i1);

		getchar();
	}
	
	return 0;
}