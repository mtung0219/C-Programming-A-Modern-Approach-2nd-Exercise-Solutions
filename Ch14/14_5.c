#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c)&&(c)<= 'z'? (c) - 'a'+'A':(c))

int main(void)
{
	char s[5];
	int i;
	strcpy(s, "abcd");
	i = 0;
	putchar(TOUPPER(s[++i]));
	//output is "D"
	// "++i" is evaluated 3 times to get to this result. twice in the conditional and once in the result

	printf("\n");

	strcpy(s, "0123");
	i = 0;
	putchar(TOUPPER(s[++i]));
	//output is "2"
	// "++i" is evalulated two times. only once in the conditional and once in the result

	return 0;
}