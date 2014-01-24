#include "stdio.h"
#include<stdlib.h>

void print()
{
	#pragma comment(linker, "/entry:print")
	#pragma comment(lib, "msvcrt.lib")

	printf("hello word\n");
	system("pause");
}


void main()
{
	printf("%s\n","hello word");
}