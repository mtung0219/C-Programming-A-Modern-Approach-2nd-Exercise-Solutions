#include <stdio.h>

int main(void)
{
	int num_grade, tens_digit;

	printf("Enter numerical grade: ");
	scanf("%d", &num_grade);

	tens_digit = num_grade / 10;

	if (num_grade > 100 || num_grade < 0) {
		printf("Error. Grade must be between 0 and 100\n");
		return 0;
	}

	printf("Letter grade: ");

	switch (tens_digit) {
	case 10: printf("A\n");
		break;
	case 9: printf("A\n");
		break;
	case 8: printf("B\n");
		break;
	case 7: printf("C\n");
		break;
	case 6: printf("D\n");
		break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		printf("F\n");
		break;
	default:
		printf("Error. Grade must be between 0 and 100\n");
		break;
	}

	return 0;
}