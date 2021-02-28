#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type* Queue;

Queue create(void);
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void insert_item(Queue q, int i);
int remove_first(Queue q);
int peek_first(Queue q);
int peek_last(Queue q);

#endif