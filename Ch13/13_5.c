#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc,  char **argv) {

	int total = 0;
	bool neg = false;

	for (int i = 1; i < argc; i++) {
		
		//parse strings to int

		char *to_int = argv[i];

		int temp_int = 0;
		neg = false;

		for (int j = 0; j < strlen(to_int);j++) {
			if (to_int[j] == '-')
				neg = true;
			else
				temp_int = temp_int * 10 + (to_int[j]-'0');

		}
		if (neg)
			total -= temp_int;
		else
			total += temp_int;

	}

	printf("%d\n", total);
	return 0;
}