#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main(void)
{

	IDENT(foo);
	return 0;
}

/* PREPROCESSOR OUTPUT:

int main(void)
{


# 7 "14_16.c"
#pragma ident "foo"
# 7 "14_16.c"
;
 return 0;
}


*/