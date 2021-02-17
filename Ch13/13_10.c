#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100


void reverse_name(char* name)
{
	char* p = name;
	char first_initial;
	char* new_pointer;

	first_initial = *p;
	p++;

	while (*p != ' ')
		p++;

	while (*p == ' ')
		p++;

	new_pointer = p; //points to last name now

	while (*p != '\0')
		p++;

	*p = ',';
	p++;
	*p = ' ';
	p++;
	*p = first_initial;
	p++;
	*p = '.';
	p++;
	*p = '\0';
	strcpy(name, new_pointer); 

	// full name reads Firstname Lastname, F.
	// strcpy copies Lastname, F. to the original name pointer.

}


int main(void)
{
	char sentence[MAX_SIZE];

	printf("Enter a first and last name: ");

	gets(sentence);

	reverse_name(&sentence[0]);
	printf("Name: %s\n", sentence);

	return 0;
}