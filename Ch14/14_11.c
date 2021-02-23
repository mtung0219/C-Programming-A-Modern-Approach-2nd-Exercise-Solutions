#include <stdio.h>

#define ERROR(msg, index) (fprintf(stderr, msg, index))

#define ERROR_variable(msg, ...) (fprintf(stderr, msg, __VA_ARGS__))

int main(void)
{
	ERROR_variable("Range error: index = %d\n", 2);
}