#include <stdio.h>

#define SIZEOF(type) printf("sizeof(%s) = %d\n", #type, sizeof(type))

int main()
{
	SIZEOF(long);
}
