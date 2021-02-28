#include <stdio.h>

// little endian ordering on x86 machines
struct IEEE_float {
	unsigned int fraction: 23;
	unsigned int exponent : 8;
	unsigned int sign : 1;
};

union float_or_ieee {
	float i;
	struct IEEE_float ifloat;
};

int main(void)
{
	union float_or_ieee x;

	x.ifloat.sign = 1;
	x.ifloat.exponent = 128;
	x.ifloat.fraction = 0;

	printf("Float value in the union is %f.\n", x.i);
}