#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGITS 10

/* external variables */
char digits[4][MAX_DIGITS*4];
char segments[10][7] = {
	{'_','|',' ','|','|','_','|'},			//0
	{' ',' ',' ','|',' ',' ','|'},			//1
	{'_',' ','_','|','|','_',' '},			//2
	{'_',' ','_','|',' ','_','|'},			//3
	{' ','|','_','|',' ',' ','|'},			//4
	{'_','|','_',' ',' ','_','|'},			//5
	{'_','|','_',' ','|','_','|'},			//6
	{'_',' ',' ','|',' ',' ','|'},			//7
	{'_','|','_','|','|','_','|'},			//8
	{'_','|','_','|',' ','_','|'}			//9
};;


/* prototypes */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);


int main(void)
{
	int position = 0;
	char c;

	clear_digits_array();
	printf("Enter a number: ");
	while ((c = getchar()) != '\n')
	{
		// if is a digit
		if (c >= '0' && c <= '9' && position < MAX_DIGITS) {
			process_digit(c - '0', position);
			position++;
		}
	}

	print_digits_array();



	return 0;
}

void clear_digits_array(void)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < MAX_DIGITS * 4; j++) {
			digits[i][j] = ' ';
		}
	}
}

void process_digit(int digit, int position)
{
	int start_pos = position * 4;
	digits[0][start_pos+1] = segments[digit][0];
	digits[1][start_pos] = segments[digit][1];
	digits[1][start_pos+1] = segments[digit][2];
	digits[1][start_pos+2] = segments[digit][3];
	digits[2][start_pos] = segments[digit][4];
	digits[2][start_pos+1] = segments[digit][5];
	digits[2][start_pos+2] = segments[digit][6];
}

void print_digits_array(void)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < MAX_DIGITS * 4; j++) {
			printf("%c", digits[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}