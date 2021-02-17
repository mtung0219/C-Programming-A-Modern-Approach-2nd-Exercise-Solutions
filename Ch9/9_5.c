#include <stdio.h>
#include <ctype.h>


void create_magic_square(int n, int magic_square[n][n]) {
	int x, y;

	//initialize board
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			magic_square[i][j] = 0;
		}
	}

	//initialize 1
	x = 0;
	y = n / 2;

	magic_square[x][y] = 1;
	for (int i = 1; i < (n * n); i++) {

		//keep original x & y positions in case next spot occupied
		int orig_x = x;
		int orig_y = y;

		//calculate potential next spot
		if (y == (n - 1))
			y = 0;
		else
			y += 1;

		if (x == 0)
			x = (n - 1);
		else
			x -= 1;

		//if spot already occupied
		if (magic_square[x][y] != 0) {
			y = orig_y;
			if (orig_x == (n - 1))
				x = 0;
			else
				x = orig_x + 1;
		}

		//write to board
		magic_square[x][y] = (i + 1);

	}
}

void print_magic_square(int n, int magic_square[n][n]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", magic_square[i][j]);
		}
		printf("\n");
	}
}


int main(void)
{

	int size;


	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &size);

	int board[size][size];

	create_magic_square(size, board);

	print_magic_square(size, board);
	return 0;
}