#include <stdio.h>
#include "stackADT_19_4.h"

int main(void)
{
	Stack s1, s2;
	int len;
	void* n;

	s1 = create();
	s2 = create();

	push(s1, "string1");
	push(s1, "string1_2");

	n = pop(s1);
	printf("Popped %s from s1\n", n);
	push(s2, "string2");
	n = pop(s1);
	printf("popped %s from s1\n", n);
	push(s2, "string2_1");

	destroy(s1);

	while (!is_empty(s2)) 
		printf("Popped %s from s2\n", pop(s2));

	push(s2, "string2_3__");
	make_empty(s2);
	if (is_empty(s2))
		printf("s2 is empty\n");
	else
		printf("s2 is not empty\n");

	destroy(s2);

	return 0;
}