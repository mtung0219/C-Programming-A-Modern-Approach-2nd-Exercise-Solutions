#include <stdio.h>
#include <ctype.h>

int main(void)
{

	int size, x, y;
	

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &size);

	int board[size][size];

	//initialize board
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = 0;
		}
	}

	//initialize 1
	x = 0;
	y = size / 2;

	board[x][y] = 1;
	for (int i = 1; i < (size * size); i++) {

		//keep original x & y positions in case next spot occupied
		int orig_x = x;
		int orig_y = y;

		//calculate potential next spot
		if (y == (size-1))
			y = 0;
		else
			y += 1;

		if (x == 0)
			x = (size - 1);
		else
			x -= 1;

		//if spot already occupied
		if (board[x][y] != 0) {
			y = orig_y;
			if (orig_x == (size - 1))
				x = 0;
			else
				x = orig_x + 1;
		}

		//write to board
		board[x][y] = i+1;

	}

	//print the board
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}