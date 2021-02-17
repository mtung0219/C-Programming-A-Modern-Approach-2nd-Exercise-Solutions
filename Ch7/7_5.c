#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c;
	int score;

	printf("Enter a word: ");

	while ((c = getchar()) != '\n') {
		c = toupper(c);

		if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' ||
			c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U')
			score += 1;
		if (c == 'D' || c == 'G')
			score += 2;
		if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
			score += 3;
		if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
			score += 4;
		if (c == 'K')
			score += 5;
		if (c == 'J' || c == 'X')
			score += 8;
		if (c == 'Q' || c == 'Z')
			score += 10;
	}

	printf("Scrabble value: %d\n", score);

	return 0;
}