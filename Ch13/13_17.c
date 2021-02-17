#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

bool is_palindrome(const char* message)
{
	char* front = message;
	char* back = message + strlen(message) - 1;

	while (front < back)
	{
		if (*front != *back)
			return false;

		front++;
		back--;
	}
	return true;
}


int main(void)
{
	char msg[SIZE] = { ' ' };

	printf("Enter a message: ");
	gets(msg);

	if (is_palindrome(msg))
		printf("Is Palindrome\n");
	else
		printf("Not palindrome\n");

	return 0;
}