#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define NUM_SIDES 6

int roll_dice(void)
{
	int result = rand() % NUM_SIDES;
	return result;
}

bool play_game(void)
{
	int point;
	int num = roll_dice()+1 + roll_dice()+1;

	printf("You rolled: %d\n", num);

	if (num == 7 || num == 11) {
		printf("You win!\n");
		return true; // game won
	}
	else if (num == 2 || num == 3 || num == 12) {
		printf("You lose!\n");
		return false; // game loss
	}
	else {
		point = num;
	}

	while (1) { // we go until we win or lose
		num = roll_dice() + 1 + roll_dice() + 1;
		printf("You rolled: %d\n", num);

		if (num == 7) {
			printf("You lose!\n");
			return false; //game loss
		}

		if (num == point) {
			printf("You win!\n");
			return true; //game won
		}
	}
}

int main(void)
{

	int wins=0, losses=0;
	bool cont = true;
	char c = ' ';

	srand((unsigned)time(NULL)); //srand cannot be in the roll_dice function

	while (cont) {
		bool outcome = play_game();
		if (outcome)
			wins += 1;
		else
			losses += 1;

		printf("\nPlay again? ");
		scanf("%c", &c);
		getchar(); //get rid of the \n

		if (c != 'y' && c != 'Y')
			cont = false;
	}

	printf("\nWins: %d  Losses: %d\n", wins, losses);
	return 0;
}