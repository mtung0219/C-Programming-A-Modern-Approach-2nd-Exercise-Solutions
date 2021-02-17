#include <stdio.h>
#include <ctype.h>


int main(void)
{
	int nums[5][5] = { [0][0] = 0, [4][4] = 0 };
	int row_totals[5] = { 0 };
	int col_totals[5] = { 0 };
	int n1=0, n2=0, n3=0, n4=0, n5=0;

	for (int i = 0; i < 5; i++) {
		printf("Enter row %d: ", i+1);
		scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

		nums[i][0] = n1;
		nums[i][1] = n2;
		nums[i][2] = n3;
		nums[i][3] = n4;
		nums[i][4] = n5;

		row_totals[i] = n1 + n2 + n3 + n4 + n5;
	}

	for (int k = 0; k < 5; k++) {
		col_totals[k] = nums[0][k] + nums[1][k] + nums[2][k] + nums[3][k] + nums[4][k];
	}
	printf("\n");
	printf("Row totals: ");

	for (int j = 0; j < 5; j++) {
		printf("%d ", row_totals[j]);
	}

	printf("\n");
	printf("Column totals: ");

	for (int j = 0; j < 5; j++) {
		printf("%d ", col_totals[j]);
	}

	return 0;
}