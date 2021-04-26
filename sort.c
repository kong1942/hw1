#include "sort.h"

//quicksort
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


void qksort(int *A, int head, int tail)
{
        int pivot;
        if(tail - head > 0)
        {
                pivot = partition(A, head, tail);
                qksort(A, head, pivot);
                qksort(A, pivot+1, tail);
        }
}

//mergesort
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

void mgsort(int *A, int *A2, int head, int tail)
{
        int pivot;
        if(head < tail)
        {
                pivot = (head + tail) / 2;
                mgsort(A, A2, head, pivot);
                mgsort(A, A2, pivot+1, tail);
                merge(A, A2, head, tail);
        }
}

//radixsort
int *rdsort(int *A, int *B)
{
	int *t;
	int *p = A;
	int *q = B;
	for(int i=0; i<MAXINTNUM; i++)
	{
		ctsort(p, q, i);
		t = p; 
		p = q; 
		q = t;
	}
	return p;
}

//countingsort
void ctsort(int *A, int *B, int digit)
{
	int C[MAXDIGIT];
	int d[MAXNUM], n;
	memset(C, 0, MAXDIGIT*sizeof(int));
	memset(d, 0, MAXNUM*sizeof(int));
	
	for(int i=0; i<MAXNUM; i++)
	{
		n = A[i];
		for(int j=0; j<digit; j++) n /= 10;
		d[i] = n%10;
		C[d[i]]++;
	}
	C[0]--;
	for(int i=1; i<MAXDIGIT; i++)
	{
		C[i] += C[i-1];
	}
	for(int i=MAXNUM-1; i>=0; i--)
	{
		B[C[d[i]]] = A[i];
		C[d[i]]--;
	}
}

//heapsort
void hpsort(int *A)
{
	

}

