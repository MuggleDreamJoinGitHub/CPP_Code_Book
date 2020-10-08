#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
void show(int* p);

int main()
{
	int i = 10;
	show(&i);

	int* p = &i;
}


void show(int * p) 
	

	printf("%p\n", p);
	printf("%p", &(*p));


}