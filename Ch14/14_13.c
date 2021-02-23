#include <stdio.h>

#define N 100

void f(void);

int main(void)
{
	f();
#ifdef N
#undef N
#endif
	return 0;
}

void f(void)
{
#if defined(N)
	printf("N is %d\n", N);
#else
	printf("N is undefined\n");
#endif
}

//results of preprocessor:
/*void f(void);

int main(void)
{
	f();



	return 0;
}

void f(void)
{



	printf("N is undefined\n");

}

OUTPUT IS: "N is undefined" We see lines 10 thru 12 are run by the preprocessor before the compiler runs f() */
