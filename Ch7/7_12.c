#include <stdio.h>
#include <ctype.h>

int main(void)
{

	char c, first_initial;
	float cur_num = 0.0f;
	_Bool dec_point;
	float dec_divisor;
	char prev_operator;
	float final_ans = 0;

	printf("Enter an expression: ");

	while ((c = getchar()) != '\n') {
		if (c <= '9' && c >= '0' && !dec_point) {
			cur_num = (float) cur_num * 10 + (c - '0');
		}
			

		else if (c == '.') { //reset decimal helepr variables
			dec_divisor = 10.0f;
			dec_point = 1;
		}
		
		else if (c <= '9' && c >= '0' && dec_point) {
			cur_num += (float) (c - '0') / dec_divisor;
			dec_divisor *= 10;
		}

		else if (c == '*' ||c == '/' || c =='-' || c=='+') { //end of parsing a num

			if (prev_operator == '*')
				final_ans *= cur_num;
			else if (prev_operator == '/')
				final_ans /= cur_num;
			else if (prev_operator == '-')
				final_ans -= cur_num;
			else
				final_ans += cur_num;

			prev_operator = c;
			cur_num = 0;
			dec_point = 0;
		}
	}

	//account for final number in the sequence
	if (prev_operator == '*')
		final_ans *= cur_num;
	else if (prev_operator == '/')
		final_ans /= cur_num;
	else if (prev_operator == '-')
		final_ans -= cur_num;
	else
		final_ans += cur_num;

	printf("Value of expression: %f", final_ans);

	return 0;
}