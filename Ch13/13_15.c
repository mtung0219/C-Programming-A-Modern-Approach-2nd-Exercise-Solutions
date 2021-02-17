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


int evaluate_RPN_expression(const char* expression)
{
	char c;
	int i1, i2;
	bool cont = true;
	int digit = 0;

	while (*expression != '\0' && cont) {
		c = *expression;
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

		expression++;
	}

	return i1;
}

int main(void)
{
	char exp[STACK_SIZE];

	printf("Enter an RPN expression: ");
	gets(exp);

	printf("Value of expression: %d\n", evaluate_RPN_expression(&exp[0]));

	return 0;
}