#include <stdio.h>

#define M 10


int main(void)
{


#if M
	printf("#if M\n");
#endif

#ifdef M
	printf("#if def M\n");
#endif

	// test fails
#ifndef M
	printf("#if ndef M\n");
#endif

#if defined(M)
	printf("#if defined M\n");
#endif

	// test fails
#if !defined(M)
	printf("#if !defined M\n");
#endif

}