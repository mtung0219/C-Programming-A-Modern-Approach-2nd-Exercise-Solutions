#include <stdio.h>

#define PI 3.1415926f

int main(void)
{
	float volume;

	printf("Volume of sphere with 10m radius is: ");

	volume = (4.0f / 3.0f) * PI * 10 * 10 * 10;
	printf("%.2f", volume);
	return 0;
}