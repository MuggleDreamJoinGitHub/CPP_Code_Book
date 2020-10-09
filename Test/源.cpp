#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "参数.h"
#include "参数2.h"


void show1(SITEINFO* g_info);
void show2(int* g_size, int* g_count);

int main()
{
	show1(g_info);
	show2(&g_size,&g_count);

}
