#include <stddef.h>
#include <stdio.h>

struct s {
	char a;
	int b[2];
	float c;
};

//in my case, there is a 3 byte hole between char a and int b[2]
int main(void)
{
	struct s s1;

	printf("size of a is %d\n", sizeof(s1.a)); // result is 1
	printf("size of b is %d\n", sizeof(s1.b)); // result is 8
	printf("size of c is %d\n", sizeof(s1.c)); // result is 4

	printf("size of entire struct is %d\n", sizeof(s1)); // result is 16


	printf("offset of a is %d\n", offsetof(struct s, a)); // result is 0
	printf("offset of b is %d\n", offsetof(struct s, b)); // result is 4
	printf("offset of c is %d\n", offsetof(struct s, c)); // result is 12
}