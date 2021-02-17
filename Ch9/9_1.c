#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


void selection_sort(int n, int arr[n])
{
	if (n == 0)
		return;
	int largest_element = 0;
	int largest_index = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		if (i == 0 || arr[i] > largest_element) {
			largest_index = i;
			largest_element = arr[i];
		}
	}

	//switch with last element of array
	temp = arr[n - 1];
	arr[n - 1] = largest_element;
	arr[largest_index] = temp;

	//recurse on first n-1 elements of array
	selection_sort(n - 1, arr);
}


int main(void)
{
	char c;
	int user_array[10] = { 0 };
	int counter = 0;
	int cur_int = 0;
	bool negative = false;

	printf("Enter a series of integers: ");
	
	//parse integers into array
	do {
		c = getchar();
		if (c == '-')
			negative = true;

		else if (c == ' ' || c == '\n') {
			if (negative)
				cur_int = -cur_int;

			user_array[counter] = cur_int;
			//reinitialize helper variables
			cur_int = 0;
			negative = false;
			counter++;
		}
		else {
			cur_int = cur_int * 10 + (c - '0');
		}
	} while (c != '\n');


	printf("Unsorted array:\n");
	for (int i = 0; i < counter; i++) {
		printf("%d ", user_array[i]);
	}
	printf("\n");

	selection_sort(counter, user_array);

	printf("Sorted array:\n");
	for (int i = 0; i < counter; i++) {
		printf("%d ", user_array[i]);
	}

	printf("\n");

	return 0;

}