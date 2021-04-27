#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXNUM 1000000
#define MAXLEN 102
#define MAXINTNUM 10
#define MAXDIGIT 10
#define MAXALPHA 53

//quick sort
int partition(int *A, int head, int tail);
void qksort(int *A, int head, int tail);
int partition2(char **A, int head, int tail);
void qksort2(char **A, int head, int tail);
//merge sort
void merge(int *A, int *A2, int head, int tail, int pivot);
void mgsort(int *A, int *A2, int head, int tail);
void merge2(char **A, char **A2, int head, int tail, int pivot);
void mgsort2(char **A, char **A2, int head, int tail);
//radix sort
void rdsort(int *A, int *B);
void ctsort(int *A, int *B, int digit);
void rdsort2(char **A, char **B);
void ctsort2(char **A, char **B, int alpha);
//heap sort
void hpsort(int *A);
