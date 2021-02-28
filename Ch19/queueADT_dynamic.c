#include <stdio.h>
#include <stdlib.h>
#include "queueADT_dynamic.h"

struct queue_type {
	int *contents;
	int first_empty;
	int to_remove;
	int num_items;
	int size;
};

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(int size)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: stack could not be created.");
	q->contents = malloc(size * sizeof(int));
	if (q->contents == NULL)
		terminate("Error in create: stack could not be created.");
	q->to_remove = 0;
	q->first_empty = 0;
	q->num_items = 0;
	q->size = size;
	return q;
}

void destroy(Queue q)
{
	make_empty(q);
	free(q->contents);
	free(q);
}

void make_empty(Queue q)
{
	while (!is_empty(q))
		remove_first(q);
}

bool is_empty(Queue q)
{
	return q->num_items == 0;
}

bool is_full(Queue q)
{
	return q->num_items == q->size;
}

void insert_item(Queue q, int i)
{
	if (is_full(q))
		terminate("Error in insert: not enough space in queue.");

	int first_empty = q->first_empty;

	q->contents[first_empty] = i;
	if (first_empty == q->size - 1)
		q->first_empty = 0;
	else
		q->first_empty++;
	q->num_items++;
}

int remove_first(Queue q)
{
	if (is_empty(q))
		terminate("Error in remove first: queue is empty.");
	int first = q->to_remove;
	q->num_items--;
	if (first == q->size - 1)
		q->to_remove = 0;
	else
		q->to_remove++;

	return q->contents[first];
}



int peek_first(Queue q)
{
	if (is_empty(q))
		terminate("Error in peek: queue is empty.");
	int first = q->to_remove;
	return q->contents[first];
}

int peek_last(Queue q)
{
	if (is_empty(q))
		terminate("Error in peek: queue is empty.");

	int last;
	if (q->first_empty == 0)
		last = q->size;
	else
		last = q->first_empty;

	return q->contents[last - 1];
}