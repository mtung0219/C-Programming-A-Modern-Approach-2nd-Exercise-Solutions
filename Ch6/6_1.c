#include <stdio.h>

int main(void)
{
	float cur_max, user_num;

	cur_max = 0.0f;

	for (;;) {
		printf("Enter a number: ");
		scanf("%f", &user_num);

		if (user_num <= 0) {
			printf("The largest number entered was %.2f\n", cur_max);
			break;
		}
		if (user_num > cur_max)
			cur_max = user_num;
	}

	return 0;
}