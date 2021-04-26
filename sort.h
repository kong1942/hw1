#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXNUM 10
#define MAXLEN 101
#define MAXLINELEN 1000001
#define MAXINTNUM 10
#define MAXDIGIT 52

//quick sort
int partition(int *A, int head, int tail);
void qksort(int *A, int head, int tail);
//merge sort
void merge(int A[], int A2[], int head, int tail);
void mgsort(int *A, int *A2, int head, int tail);
//radix sort
int *rdsort(int *A, int *B);
void ctsort(int *A, int *B, int digit);
//heap sort
void hpsort(int *A);
