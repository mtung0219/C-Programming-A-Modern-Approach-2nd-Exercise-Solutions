#include <stdio.h>
#include <string.h>


#define SIZE 100

void reverse(char* message)
{
	char temp;
	char* front = message;
	char* back = message + strlen(message)-1;

	while (front < back)
	{
		temp = *front;
		*front = *back;
		*back = temp;

		front++;
		back--;
	}
}

int main(void)
{
	char msg[SIZE] = { ' ' };
	int counter = 0;
	char c;
	printf("Enter a message: ");

	gets(msg);

	reverse(&msg[0]);
	printf("Reversed message: %s\n", msg);
	return 0;
}