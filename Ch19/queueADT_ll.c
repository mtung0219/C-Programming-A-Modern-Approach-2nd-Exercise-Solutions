#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
	int data;
	struct node* next;
};

struct queue_type {
	struct node* first;
	struct node* last;
	int num_items;
};

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: stack could not be created.");
	q->first = NULL;
	q->last = NULL;
	q->num_items = 0;
	return q;
}

void destroy(Queue q)
{
	make_empty(q);
	free(q);
}

void make_empty(Queue q)
{
	while (!is_empty(q))
		remove_first(q);
}

bool is_empty(Queue q)
{
	return q->first == NULL;
}

bool is_full(Queue q)
{
	return false;
}

void insert_item(Queue q, int i)
{
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in insert: not enough space in queue.");

	new_node->data = i;
	new_node->next = NULL;

	if (q->first == NULL) {
		q->first = new_node;
		q->last = q->first;
	}
	else {
		q->last->next = new_node;
		q->last = new_node;
	}

	q->num_items++;
}

int remove_first(Queue q)
{
	if (is_empty(q))
		terminate("Error in remove first: queue is empty.");

	struct node* old_first;
	int i;
	old_first = q->first;
	i = old_first->data;
	q->first = old_first->next;

	q->num_items--;

	free(old_first);
	return i;
}



int peek_first(Queue q)
{
	if (is_empty(q))
		terminate("Error in peek: queue is empty.");
	return q->first->data;
}

int peek_last(Queue q)
{
	if (is_empty(q))
		terminate("Error in peek: queue is empty.");

	return q->last->data;
}