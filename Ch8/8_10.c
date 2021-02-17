#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_TIMES 8

int main(void)
{
	int departures[NUM_TIMES] = { 8 * 60, 9 * 60 + 43, 11*60+19,12*60+47,14*60,15*60+45,19*60,21*60+45 };
	int arrivals[NUM_TIMES] = { 10*60+16,11*60+52,13*60+31,15*60,16*60+8,17*60+55,21*60+20,23*60+58 };

	int hour, min, since_midnight, closest_departure, closest_diff, closest_arrival;
	int dep_hour, dep_min, arr_hour, arr_min;

	closest_diff = 24 * 60;
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &min);

	since_midnight = hour * 60 + min;

	for (int i = 0; i < NUM_TIMES; i++) {
		int diff = abs(since_midnight - departures[i]);
		if (diff < closest_diff) {
			closest_diff = diff;
			closest_departure = departures[i];
			closest_arrival = arrivals[i];
		}
	}

	dep_hour = closest_departure / 60;
	dep_min = closest_departure % 60;


	arr_hour = closest_arrival / 60;
	arr_min = closest_arrival % 60;

	printf("Closest departure time is %d:%2.2d, arriving at %d:%2.2d\n", 
		dep_hour, dep_min, arr_hour, arr_min);


	return 0;
}