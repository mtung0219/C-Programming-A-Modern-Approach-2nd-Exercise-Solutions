#include <stdio.h>


// overflow for int occurs for me at i = 46341
// short failed at i = 32768
// i didn't try long type as i did not have the patience for that..
// these numbers may vary on your machine

// 32767 is the maximum positive integer that can be expressed using 16 bits (0111 1111 1111 1111)
// integer version failed when i*i when from 31 to 32 bits. this makes sense since the leftmost bit is for
// sign, and the result became very large negative numbers.

int main(void)
{
	int n;
	int i;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in tabale: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		printf("%10d%10d\n", i, i * i);

	return 0;
}