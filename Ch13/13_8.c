#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 30

int read_line(char str[], int n);

int compute_scrabble_value(const char* word)
{
	int score = 0;
	char c = toupper(*word);

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

	return score;

}

int main(void)
{
	char c;
	int score = 0;

	char word[MAX_SIZE+1];
	char* p;

	printf("Enter a word:\n");
	scanf("%s", word);

	//p points to start of word char array
	p = word;

	//while word is not ended
	while (*p) {
		score += compute_scrabble_value(p);
		p++; //point to next letter of word
	}
	printf("Scrabble value: %d\n", score);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}