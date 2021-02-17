#include <stdio.h>

int main(void)
{
	int num;

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	int tens_digit = num / 10;
	int ones_digit = num % 10;

	printf("You entered the number ");

	switch (tens_digit) {
	case 9:
		printf("ninety-");
		break;
	case 8:
		printf("eighty-");
		break;
	case 7:
		printf("seventy-");
		break;
	case 6:
		printf("sixty-");
		break;
	case 5:
		printf("fifty-");
		break;
	case 4:
		printf("forty-");
		break;
	case 3:
		printf("thirty-");
		break;
	case 2:
		printf("twenty-");
		break;
	case 1:
		if (num == 11)
			printf("eleven.\n");
		if (num == 12)
			printf("twelve.\n");
		if (num == 13)
			printf("thirteen.\n");
		if (num == 14)
			printf("fourteen.\n");
		if (num == 15)
			printf("fifteen.\n");
		if (num == 16)
			printf("sixteen.\n");
		if (num == 17)
			printf("seventeen.\n");
		if (num == 18)
			printf("eighteen.\n");
		if (num == 19)
			printf("nineteen.\n");
		return 0;
		break;
	}

	switch (ones_digit) {
	case 9:
		printf("nine.\n");
		break;
	case 8:
		printf("eight.\n");
		break;
	case 7:
		printf("seven.\n");
		break;
	case 6:
		printf("six.\n");
		break;
	case 5:
		printf("five.\n");
		break;
	case 4:
		printf("four.\n");
		break;
	case 3:
		printf("three.\n");
		break;
	case 2:
		printf("two.\n");
		break;
	case 1:
		printf("one.\n");
		break;
	}



	return 0;
}