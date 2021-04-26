#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10


void merge(int A[], int A2[], int head, int tail)
{
	int pivot = (head+tail)/2;
	int i = head, j = pivot+1;
	for(int k = head; k < tail+1; k++)
	{
		if((A[i] <= A[j] && i < pivot+1) || j == tail+1)
		{
			A2[k] = A[i];
			i++;
		}
		else if((A[i] > A[j] && j < tail+1) || i == pivot+1)
		{
			A2[k] = A[j];
			j++;
		}
	}
	for(int k = head; k < tail+1; k++)
	{
		A[k] = A2[k];
	}
}

void mergesort(int A[], int A2[], int head, int tail)
{
	int pivot;
	if(head < tail)
	{
		pivot = (head + tail) / 2;
		mergesort(A, A2, head, pivot);
		mergesort(A, A2, pivot+1, tail);
		merge(A, A2, head, tail);
	}
}


int main()
{
	srand(2); rand();
	int A[MAXNUM];
	int A2[MAXNUM];
	for(int i=0; i<MAXNUM; i++)
	{
		A[i] = rand();
	}
	mergesort(A, A2, 0, MAXNUM-1);
	for(int i=0; i<MAXNUM; i++)
	{
		printf("%d\n", A[i]);
	}

	return 0;
}
