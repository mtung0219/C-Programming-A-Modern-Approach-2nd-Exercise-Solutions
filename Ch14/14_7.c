#include <stdio.h>

#define GENERIC_MAX(type) \
type type##_max(type x, type y) \
{							\
	return x > y ? x :y;    \
}

int main(void)
{
	GENERIC_MAX(long);
	// preprocessor output is long long_max(long x, long y) {return x > y ? x : y};

	printf("%ld\n", long_max(2,5));

	//i get error:duplicate 'unsigned' when attempting GENERIC_MAX(unsigned long)

	// reason is the preprocessor outputs "unsigned long unsigned long_max( . . . etc)"

	// to fix this, we can define a custom type:

	typedef unsigned long ULONG;

	GENERIC_MAX(ULONG);

	printf("%ld\n", ULONG_max(2, 5));

}