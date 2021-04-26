#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 10

int main()
{
	srand(2); rand();
	int A[2][MAXNUM];
	for(int i=0; i<MAXNUM; i++)
		for(int j=0; j<2; j++)
			A[j][i] = rand()%10;
	

	return 0;
}
