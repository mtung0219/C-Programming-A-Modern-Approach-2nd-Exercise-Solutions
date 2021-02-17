#include <stdio.h>
#include <ctype.h>


int main(void)
{
	int nums[5][5] = { [0] [0] = 0,[4][4] = 0 };
	int row_totals[5] = { 0 };
	int col_totals[5] = { 0 };
	int quiz_lowest[5] = {100,100,100,100,100 };
	int quiz_highest[5] = { 0 };
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;

	for (int i = 0; i < 5; i++) {
		printf("Enter quizzes for student %d: ", i + 1);
		scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

		nums[i][0] = n1;
		nums[i][1] = n2;
		nums[i][2] = n3;
		nums[i][3] = n4;
		nums[i][4] = n5;

		row_totals[i] = n1 + n2 + n3 + n4 + n5;
	}

	for (int k = 0; k < 5; k++) {
		for (int j = 0; j < 5; j++) {
			col_totals[k] += nums[j][k];

			if (nums[j][k] < quiz_lowest[k])
				quiz_lowest[k] = nums[j][k];

			if (nums[j][k] > quiz_highest[k])
				quiz_highest[k] = nums[j][k];
		}
	}
	printf("\n");
	printf("Total score of students: ");

	for (int j = 0; j < 5; j++) {
		printf("%d ", row_totals[j]);
	}

	printf("\n");
	printf("Average score of students: ");

	for (int j = 0; j < 5; j++) {
		printf("%.1f ", row_totals[j] / 5.0f);
	}

	printf("\n");
	printf("Average score of quizzes: ");

	for (int j = 0; j < 5; j++) {
		printf("%.1f ", col_totals[j] / 5.0f);
	}

	printf("\n");
	printf("High score of quizzes: ");

	for (int j = 0; j < 5; j++) {
		printf("%d ", quiz_highest[j]);
	}
	printf("\n");
	printf("Low score of quizzes: ");

	for (int j = 0; j < 5; j++) {
		printf("%d ", quiz_lowest[j]);
	}
	return 0;
}