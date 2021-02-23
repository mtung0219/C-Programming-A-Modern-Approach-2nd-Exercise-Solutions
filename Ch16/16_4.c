#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct parts {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	int price;
};
int find_part(int number, int num_parts, struct parts inventory[]);
int insert(int num_parts, struct parts inventory[]);
void search(int num_parts, struct parts inventory[]);
void update(int num_parts, struct parts inventory[]);
void print(int num_parts, struct parts inventory[]);
void merge(int l, int m, int r, struct parts inventory[]);
void mergesort(int l, int r, struct parts inventory[]);
void change_price(int num_parts, struct parts inventory[]);

// I decided to implement mergesort as a way to have the printed list be sorted by part number.


int main(void)
{
	struct parts inventory[MAX_PARTS];

	int num_parts = 0;
	int new_numparts = -1;
	char code;
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;
		switch (code) {
		case 'i':
			new_numparts = insert(num_parts, inventory);
			if (new_numparts >= 0)
				num_parts = new_numparts;
			break;
		case 's': search(num_parts, inventory);
			break;
		case 'u': update(num_parts, inventory);
			break;
		case 'p': print(num_parts, inventory);
			break;
		case 'w': change_price(num_parts, inventory);
			break;
		case 'q': return 0;
		default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

void change_price(int num_parts, struct parts inventory[])
{
	int i, number, px;
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number, num_parts, inventory);
	if (i >= 0) {
		printf("Enter new price: ");
		scanf("%d", &px);
		inventory[i].price = px;
	}
	else
		printf("Part not found.\n");
}

int find_part(int number, int num_parts, struct parts inventory[])
{
	int i;
	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

int insert(int num_parts, struct parts inventory[])
{
	int part_number;
	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return -1;
	}
	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number, num_parts, inventory) >= 0) {
		printf("Part already exists.\n");
		return -1;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	printf("Enter price: ");
	scanf("%d", &inventory[num_parts].price);
	num_parts++;
	return num_parts;
}

void search(int num_parts, struct parts inventory[])
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number, num_parts, inventory);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(int num_parts, struct parts inventory[])
{
	int i, number, change;
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number, num_parts, inventory);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void print(int num_parts, struct parts inventory[])
{
	int i;
	mergesort(0, num_parts - 1, inventory);
	printf("Part Number    Part Name     Quality on Hand     Price\n");
	for (i = 0; i < num_parts; i++)
		printf("%7d    %-25s%1ld    %d\n", inventory[i].number,
			inventory[i].name, inventory[i].on_hand, inventory[i].price);
}

void mergesort(int l, int r, struct parts inventory[])
{
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(l, m, inventory);
		mergesort(m + 1, r, inventory);

		merge(l, m, r, inventory);
	}

}

void merge(int l, int m, int r, struct parts inventory[])
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
