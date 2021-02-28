#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100
#define INITIAL_PARTS 10

struct parts {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

struct parts* inventory;

int num_parts = 0;
int max_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int compare_parts(const void* p, const void* q);


int main(void)
{
	inventory = malloc(INITIAL_PARTS * sizeof(struct parts));
	if (inventory == NULL) {
		printf("not enough space to initially allocate inventory!\n");
		exit(EXIT_FAILURE);
	}
	max_parts = INITIAL_PARTS;
	char code;
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;
		switch (code) {
		case 'i': insert();
			break;
		case 's': search();
			break;
		case 'u': update();
			break;
		case 'p': print();
			break;
		case 'q': return 0;
		default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

int find_part(int number)
{
	int i;
	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(void)
{
	int part_number;
	struct parts* re;
	if (num_parts == max_parts) {
		max_parts *= 2;
		re = realloc(inventory, max_parts * sizeof(struct parts));
		if (re == NULL) {
			printf("not enough space to reallocate inventory!\n");
			exit(EXIT_FAILURE);
		}
		inventory = re;
	}
	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}

void search(void)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(void)
{
	int i, number, change;
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void print(void)
{
	int i;
	qsort(inventory, num_parts, sizeof(struct parts), compare_parts);
	printf("Part Number    Part Name     Quality on Hand\n");
	for (i = 0; i < num_parts; i++)
		printf("%7d    %-25s%1ld\n", inventory[i].number,
			inventory[i].name, inventory[i].on_hand);
}

int compare_parts(const void* p, const void* q)
{
	if (((struct parts*)p)->number <
		((struct parts*)q)->number)
		return -1;
	else if (((struct parts*)p)->number ==
		((struct parts*)q)->number)
		return 0;
	else
		return 1;
}
