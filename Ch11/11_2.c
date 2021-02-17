#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void find_closest_flight(int desired_time, int* departure_time, int* arrival_time)
{
	int d1, d2, d3, d4, d5, d6, d7, d8;

	d1 = abs(desired_time - 8 * 60 - 0);
	d2 = abs(desired_time - 9 * 60 - 43);
	d3 = abs(desired_time - 11 * 60 - 19);
	d4 = abs(desired_time - 12 * 60 - 47);
	d5 = abs(desired_time - 14 * 60 - 0);
	d6 = abs(desired_time - 15 * 60 - 45);
	d7 = abs(desired_time - 19 * 60 - 0);
	d8 = abs(desired_time - 21 * 60 - 45);

	int min_diff = 24 * 60;
	int flight_num = 0;

	if (d1 < min_diff) {
		flight_num = 1;
		min_diff = d1;
	}
	if (d2 < min_diff) {
		flight_num = 2;
		min_diff = d2;
	}
	if (d3 < min_diff) {
		flight_num = 3;
		min_diff = d3;
	}
	if (d4 < min_diff) {
		flight_num = 4;
		min_diff = d4;
	}
	if (d5 < min_diff) {
		flight_num = 5;
		min_diff = d5;
	}
	if (d6 < min_diff) {
		flight_num = 6;
		min_diff = d6;
	}
	if (d7 < min_diff) {
		flight_num = 7;
		min_diff = d7;
	}
	if (d8 < min_diff) {
		flight_num = 8;
		min_diff = d8;
	}

	switch (flight_num) {
	case 1: printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
		break;
	case 2: printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
		break;
	case 3: printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
		break;
	case 4: printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
		break;
	case 5: printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
		break;
	case 6: printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
		break;
	case 7: printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
		break;
	case 8: printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
		break;
	}

}


int main(void)
{

	int hour, min, min_since_midnight;
	int departure_time, arrival_time;
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &min);

	min_since_midnight = hour * 60 + min;

	find_closest_flight(min_since_midnight, &departure_time, &arrival_time);



	return 0;
}