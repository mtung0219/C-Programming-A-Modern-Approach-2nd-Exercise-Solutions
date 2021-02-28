#include <stdio.h>
#include "queueADT.h"

int main(void)
{
	Queue q1, q2;
	int n;

	//FOR 19_5 and 19_7
	q1 = create();
	q2 = create();

	//FOR 19_6
	//q1 = create(200);
	//q2 = create(200);

	insert_item(q1, 1);
	//insert_item(q1, 2);

	n = remove_first(q1);
	printf("Removed %d from s1\n", n);
	insert_item(q2, n);

	insert_item(q1, 2);

	n = remove_first(q1);
	printf("Removed %d from s1\n", n);
	insert_item(q2, n);
	insert_item(q2, 67);
	insert_item(q2, 68);
	insert_item(q2, 69);
	insert_item(q2, 7000);
	destroy(q1);

	while (!is_empty(q2))
		printf("Removed %d from s2\n", remove_first(q2));

	insert_item(q2, 3);
	make_empty(q2);
	if (is_empty(q2))
		printf("q2 is empty\n");
	else
		printf("q2 is not empty\n");

	destroy(q2);

	return 0;
}