#include <stdio.h>

#define PI 3.1415926f

int main(void)
{
	float volume, radius;

	printf("Please enter radius of sphere (in meters): ");
	scanf("%f", &radius);s

	printf("Volume of sphere (in meters) is: ");
	volume = (4.0f / 3.0f) * PI * radius * radius * radius;
	printf("%.2f", volume);
	return 0;
}