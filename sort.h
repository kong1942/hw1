#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXNUM 10000
#define MAXLEN 102
#define MAXINTNUM 10
#define MAXDIGIT 10
#define MAXALPHA 52

//quick sort
int partition(int *A, int head, int tail);
void qksort(int *A, int head, int tail);
int partition2(char A[][MAXLEN], int head, int tail);
void qksort2(char A[][MAXLEN], int head, int tail);
//merge sort
void merge(int A[], int A2[], int head, int tail);
void mgsort(int *A, int *A2, int head, int tail);
void merge2(char A[][MAXLEN], char A2[][MAXLEN], int head, int tail);
void mgsort2(char A[][MAXLEN], char A2[][MAXLEN], int head, int tail);
//radix sort
int *rdsort(int *A, int *B);
void ctsort(int *A, int *B, int digit);
void rdsort2(char A[][MAXLEN], char B[][MAXLEN]);
void ctsort2(char A[][MAXLEN], char B[][MAXLEN], int alpha);
//heap sort
void hpsort(int *A);
