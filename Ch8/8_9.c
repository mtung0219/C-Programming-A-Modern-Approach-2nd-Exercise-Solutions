#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_DIRECTIONS 4

int main(void)
{
	int x = 0, y = 0, direction;
	bool left_ok, up_ok, down_ok, right_ok;
	char board[10][10] =
	{ { '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.','.' } };


	srand((unsigned)time(NULL));

	

	for (int i = 0; i < 26; i++) {

		//reinitialize checkers
		left_ok = false;
		right_ok = false;
		up_ok = false;
		down_ok = false;

		char to_put = 'A' + i;
		board[x][y] = to_put;

		//check if there is a valid move;
		if (x != 0 && board[x - 1][y] == '.')
			left_ok = true;
		if (x != 9 && board[x + 1][y] == '.')
			right_ok = true;
		if (y != 0 && board[x][y - 1] == '.')
			up_ok = true;
		if (y != 9 && board[x][y + 1] == '.')
			down_ok = true;

		if (!left_ok && !right_ok && !up_ok && !down_ok)
			break;


		direction = rand() % NUM_DIRECTIONS;
		// 0 is left
		// 1 is up
		// 2 is right
		// 3 is down

		//redo rand if necesary
		while ((direction == 0 && !left_ok) || (direction == 1 && !up_ok) || 
			(direction == 2 && !right_ok) || (direction == 3 && !down_ok))
			direction = rand() % NUM_DIRECTIONS;

		if (direction == 0)
			x -= 1;
		else if (direction == 1)
			y -= 1;
		else if (direction == 2)
			x += 1;
		else if (direction == 3)
			y += 1;

	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}