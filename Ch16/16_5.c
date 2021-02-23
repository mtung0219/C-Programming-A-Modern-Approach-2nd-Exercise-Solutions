#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define MAX_FLIGHTS 8
int main(void)
{

	struct flights {
		int departure_time;
		int arrival_time;
	};

	struct flights flight_list[MAX_FLIGHTS] = { {480,616},{583,712},
	{679,811} ,{767,900} ,
	{840,968} ,{945,1075} ,
	{1140,1280} ,{1305,1438} };

	int hour, min, min_since_midnight;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &min);

	min_since_midnight = hour * 60 + min;

	int min_diff = 1440;
	int closest_flight;

	for (int i = 0; i < MAX_FLIGHTS; i++) {
		if (abs(min_since_midnight - flight_list[i].departure_time) < min_diff) {
			min_diff = abs(min_since_midnight - flight_list[i].departure_time);
			closest_flight = i;
		}
	}

	printf("Closest flight is %d.\n", closest_flight);
	return 0;
}