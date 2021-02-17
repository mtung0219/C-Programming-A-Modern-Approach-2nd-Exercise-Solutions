/* STILL IN PROGRESS */













/* Classifies a poker hand */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int hand[5][2]; /* to replace num_in_rank and num_in_suit arrays */
bool straight, flush, four, three;
int pairs; /* can be 0, 1, 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);
bool card_exists(int, int);

int main(void)
{
	for (;;) {
		read_cards();
		analyze_hand();
		print_result();
	}
}

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	int rank, suit;
	bool bad_cards;
	int cards_read = 0;

	while (cards_read < NUM_CARDS) {
		bad_cards = false;
		printf("Enter a card: ");

		rank_ch = getchar();
		switch (rank_ch) {
		case '0': exit(EXIT_SUCCESS);
		case '2': rank = 0; break;
		case '3': rank = 1; break;
		case '4': rank = 2; break;
		case '5': rank = 3; break;
		case '6': rank = 4; break;
		case '7': rank = 5; break;
		case '8': rank = 6; break;
		case '9': rank = 7; break;
		case 't': rank = 8; break;
		case 'j': rank = 9; break;
		case 'q': rank = 10; break;
		case 'k': rank = 11; break;
		case 'a': rank = 12; break;
		default: bad_cards = true;
		}

		suit_ch = getchar();
		switch (suit_ch) {
		case 'c': case 'C': suit = 0; break;
		case 'd': case 'D': suit = 1; break;
		case 'h': case 'H': suit = 2; break;
		case 's': case 'S': suit = 3; break;
		default: bad_cards = true;
		}

		while ((ch = getchar()) != '\n')
			if (ch != ' ') bad_cards = true;

		if (bad_cards)
			printf("Bad card; ignored.\n");
		else if (card_exists(rank, suit))
			printf("Duplicate card; ignored.\n");
		else {

			hand[cards_read][0] = rank;
			hand[cards_read][1] = suit;
			cards_read++;
		}
	}
}

bool card_exists(int rank, int suit) {
	for (int i = 0; i < 5; i++) {
		if (hand[i][0] == rank && hand[i][1] == suit)
			return true;
	}
	return false;
}

void analyze_hand(void)
{
	int num_consec = 0;
	int rank, suit;
	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	for (suit = 0; suit < NUM_SUITS; suit++)

		if (num_in_suit[suit] == NUM_CARDS)
			flush = true;

	/* check for straight */
	rank = 0;
	while (num_in_rank[rank] == 0) rank++;
	for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
		num_consec++;
	if (num_consec == NUM_CARDS) {
		straight = true;
		return;
	}

	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	for (rank = 0; rank < NUM_RANKS; rank++) {
		if (num_in_rank[rank] == 4) four = true;
		if (num_in_rank[rank] == 3) three = true;
		if (num_in_rank[rank] == 2) pairs++;
	}
}

void print_result(void)
{
	if (straight && flush) printf("Straight flush");
	else if (four) printf("Four of a kind");
	else if (three && pairs == 1) printf("Full house");
	else if (flush) printf("Flush");
	else if (straight) printf("Straight");
	else if (three) printf("Three of a kind");
	else if (pairs == 2) printf("Two pairs");
	else if (pairs == 1) printf("Pair");
	else			printf("High card");

	printf("\n\n");
}