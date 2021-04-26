#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXNUM 10
#define MAXLEN 101

int partition(int *A, int head, int tail)
{
	int j=head+1;
	int tmp;
	int pivot = head;
	int key = A[pivot];
	for(int i=head+1; i<tail; i++)
	{
		if(A[i] < key)
		{
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			j++;
		}
	}
	A[head] = A[j-1];
	A[j-1] = key;
	return j-1;
}
/*
int partition2(int *A[], int head, int tail)
{
	int j=head+1;
	char tmp[MAXLEN];
	int pivot = head;
	char key[MAXLEN];
	strcpy(key, A[pivot]);

	for(int i=head+1; i<tail; i++)
	{
		if(strcmp(A[i], key) < 0)
		{
			strcpy(tmp, A[i]);
			strcpy(A[i], A[j]);
			strcpy(A[j], tmp);
			j++;
		}
	}
	strcpy(A[head], A[j-1]);
	strcpy(A[j-1], key);
	return j-1;
}
*/
void quicksort(int *A, int head, int tail)
{
	int pivot;
	if(tail - head > 0) 
	{
		pivot = partition(A, head, tail);
		quicksort(A, head, pivot);
		quicksort(A, pivot+1, tail);
	}
}
/*
void quicksort2(int *A[], int head, int tail)
{
	int pivot;
	if(tail - head > 0) 
	{
		pivot = partition2(A, head, tail);
		quicksort2(A, head, pivot);
		quicksort2(A, pivot+1, tail);
	}
}
*/
int main()
{
	srand(2);rand();
	int A[MAXNUM];
	for(int i=0; i<MAXNUM; i++)
	{
		A[i] = rand();
	}
	quicksort(A, 0, MAXNUM);
	//quicksort2(A, 0, MAXNUM);
	for(int i=0; i<MAXNUM; i++)
	{
		printf("%d\n", A[i]);
	}
	return 0;
}
