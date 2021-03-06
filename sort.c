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

int partition2(char **A, int head, int tail)
{
        int j=head+1;
        char tmp[MAXLEN];
        int pivot = head;
        char key[MAXLEN];
	memcpy(key, A[pivot], sizeof(char)*MAXLEN);

        for(int i=head+1; i<tail; i++)
        {
                if(strcmp(A[i], key) < 0)
                {
                        memcpy(tmp, A[i], sizeof(char)*MAXLEN);
                        memcpy(A[i], A[j], sizeof(char)*MAXLEN);
                        memcpy(A[j], tmp, sizeof(char)*MAXLEN);
                        j++;
                }
        }
        memcpy(A[head], A[j-1], sizeof(char)*MAXLEN);
        memcpy(A[j-1], key, sizeof(char)*MAXLEN);
        return j-1;
}

void qksort2(char **A, int head, int tail)
{
        int pivot;
        if(tail - head > 0)
        {
                pivot = partition2(A, head, tail);
                qksort2(A, head, pivot);
                qksort2(A, pivot+1, tail);
        }
}

//mergesort
void merge(int *A, int *A2, int head, int tail, int pivot)
{
        int i = head, j = pivot+1;
        for(int k = head; k < tail+1; k++)
        {
                if(j == tail+1 || (A[i] <= A[j] && i < pivot+1))
                {
                        A2[k] = A[i];
                        i++;
                }
                else if(i == pivot+1 || (A[i] > A[j] && j < tail+1))
                {
                        A2[k] = A[j];
                        j++;
                }
        }
	memcpy(&A[head], &A2[head], sizeof(int)*(tail-head+1));
}

void mgsort(int *A, int *A2, int head, int tail)
{
        int pivot;
        if(head < tail)
        {
                pivot = (head + tail) / 2;
                mgsort(A, A2, head, pivot);
                mgsort(A, A2, pivot+1, tail);
                merge(A, A2, head, tail, pivot);
        }
}

void merge2(char **A, char **A2, int head, int tail, int pivot)
{
        int i = head, j = pivot+1;
        for(int k = head; k < tail+1; k++)
        {
                if(j == tail+1 || (strcmp(A[i], A[j]) <= 0 && i < pivot+1))
                {
			memcpy(A2[k], A[i], sizeof(char)*MAXLEN);
                        i++;
                }
                else if(i == pivot+1 || (strcmp(A[i], A[j]) > 0 && j < tail+1))
                {
			memcpy(A2[k], A[j], sizeof(char)*MAXLEN);
                        j++;
                }
        }
	memcpy(A[head], A2[head], sizeof(char)*MAXLEN*(tail-head+1));
}

void mgsort2(char **A, char **A2, int head, int tail)
{
        int pivot;
        if(head < tail)
        {
                pivot = (head + tail) / 2;
                mgsort2(A, A2, head, pivot);
                mgsort2(A, A2, pivot+1, tail);
                merge2(A, A2, head, tail, pivot);
        }
}

//radixsort + counting sort
void rdsort(int *A, int *B)
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
	if(p != A) memcpy(A, B, sizeof(int)*MAXNUM);
}

void ctsort(int *A, int *B, int digit)
{
	int C[MAXDIGIT];
	int d[MAXNUM], n;
	memset(C, 0, MAXDIGIT*sizeof(int));
	
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

void rdsort2(char **A, char **B)
{
	char **t;
	char **p = A;
	char **q = B;
	
	for(int i=MAXLEN-3; i>=0; i--)
	{
		ctsort2(p, q, i);
		t = p;
		p = q;
		q = t;
	}
	if(p != A) memcpy(A[0], B[0], sizeof(char)*MAXLEN*MAXNUM);
}

void ctsort2(char **A, char **B, int alpha)
{
	int C[MAXALPHA];
	int n[MAXNUM];
	memset(C, 0, MAXALPHA*sizeof(int));
	
	for(int i=0; i<MAXNUM; i++)
	{
		if(A[i][alpha] >= 'a' && A[i][alpha] <= 'z') n[i] = (A[i][alpha] - 'a') + 27;
		else if(A[i][alpha] >= 'A' && A[i][alpha] <= 'Z') n[i] = A[i][alpha] - 'A' + 1;
		else if(A[i][alpha] == '\0') n[i] = 0;
		C[n[i]]++;
	}
	C[0]--;
	for(int i=1; i<MAXALPHA; i++)
	{
		C[i] += C[i-1];
	}
	for(int i=MAXNUM-1; i>=0; i--)
	{
		memcpy(B[C[n[i]]], A[i], sizeof(char)*MAXLEN);
		C[n[i]]--;
	}
}

//heapsort
void hpsort(int *A)
{
	

}
