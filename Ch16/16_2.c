#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct parts {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void merge(int l, int m, int r);
void mergesort(int l, int r);

// I decided to implement mergesort as a way to have the printed list be sorted by part number.


int main(void)
{
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
	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
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
	mergesort(0, num_parts-1);
	printf("Part Number    Part Name     Quality on Hand\n");
	for (i = 0; i < num_parts; i++)
		printf("%7d    %-25s%1ld\n", inventory[i].number,
			inventory[i].name, inventory[i].on_hand);
}

void mergesort(int l, int r)
{
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(l, m);
		mergesort(m + 1, r);

		merge(l, m, r);
	}

}

void merge(int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	struct parts L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = inventory[l + i];

	for (j = 0; j < n2; j++)
		R[j] = inventory[(m + 1) + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i].number <= R[j].number) {
			inventory[k] = L[i];
			i++;
		}
		else {
			inventory[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		inventory[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		inventory[k] = R[j];
		j++;
		k++;
	}


	return;
}
