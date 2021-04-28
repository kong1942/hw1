#include "sort.h"
#include <sys/time.h>

int main(int argc, char **argv)
{
	if(argc != 3) exit(0);
	struct timeval start;
	struct timeval end;
	double diff;
	FILE *fp;
	FILE *fp2;
	int *numArr;
	numArr = (int *)malloc(sizeof(int) * MAXNUM);
	memset(numArr, 0, MAXNUM*sizeof(int));
	char **wdArr;
	wdArr = (char **)malloc(sizeof(char *) * MAXNUM);
	for(int i=0; i<MAXNUM; i++)
	{
		wdArr[i] = (char *)malloc(sizeof(char) * MAXLEN);
		memset(wdArr[i], '\0', sizeof(char)*MAXLEN);
	}

	if(!strcmp(argv[2], "n"))
	{
		fp = fopen("dataset1.txt", "r");
		int *ptr = &numArr[0];
		
		while(fscanf(fp, "%d", ptr) && ptr - numArr < MAXNUM) { ptr++; }
		ptr = numArr;
		if(!strcmp(argv[1], "qk")) 
		{
			fp2 = fopen("result.txt", "w");
			fprintf(fp2, "-----------------------------------\n");
			gettimeofday(&start, NULL);
			qksort(numArr, 0, MAXNUM);
			gettimeofday(&end, NULL);
			diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			fprintf(fp2, "| quick sort | number | %.4fsec |\n", diff/1000000);
		}

		else 
		{
			fp2 = fopen("result.txt", "a");
			int *numArr2;
			numArr2 = (int *)malloc(sizeof(int) * MAXNUM);
			memset(numArr2, 0, MAXNUM*sizeof(int));
			
			if(!strcmp(argv[1], "mg")) 
			{
				gettimeofday(&start, NULL);
				mgsort(numArr, numArr2, 0, MAXNUM-1);
				gettimeofday(&end, NULL);
				diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
				fprintf(fp2, "| merge sort | number | %.4fsec |\n", diff/1000000);
			}
			else if(!strcmp(argv[1], "rd")) 
			{
				gettimeofday(&start, NULL);
				rdsort(numArr, numArr2);
				gettimeofday(&end, NULL);
				diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
				fprintf(fp2, "| radix sort | number | %.4fsec |\n", diff/1000000);
			}
			free(numArr2);
		}

//		while(ptr - numArr < MAXNUM) { printf("%d\n", *ptr); ptr++; }
	}
	
	else if(!strcmp(argv[2], "w"))
	{
		int i=0;
		fp = fopen("dataset2.txt", "r");
		fp2 = fopen("result.txt", "a");
		while(fgets(wdArr[i], MAXLEN, fp)) { i++; }
		if(!strcmp(argv[1], "qk"))
		{
			gettimeofday(&start, NULL);
			qksort2(wdArr, 0, i);
			gettimeofday(&end, NULL);
			diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			fprintf(fp2, "| quick sort | alpha  | %.4fsec |\n", diff/1000000);
		}
		else 
		{
			char **wdArr2;
			wdArr2 = (char **)malloc(sizeof(char *) * MAXNUM);
			for(int j=0; j<MAXNUM; j++)
			{
				wdArr2[j] = (char *)malloc(sizeof(char) * MAXLEN);
				memset(wdArr2[j], '\0', sizeof(char)*MAXLEN);
			}
			
			if(!strcmp(argv[1], "mg"))
			{
				gettimeofday(&start, NULL);
				mgsort2(wdArr, wdArr2, 0, MAXNUM-1);
				gettimeofday(&end, NULL);
				diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
				fprintf(fp2, "| merge sort | alpha  | %.4fsec |\n", diff/1000000);
			}
			else if(!strcmp(argv[1], "rd"))
			{
				gettimeofday(&start, NULL);
				rdsort2(wdArr, wdArr2);
				gettimeofday(&end, NULL);
				diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
				fprintf(fp2, "| radix sort | alpha  | %.4fsec |\n", diff/1000000);
			}
			for(int j=0; j<MAXNUM; j++)
			{
				free(wdArr2[j]);
			}
			free(wdArr2);
		}
//		for(int i=0; i<MAXNUM; i++) printf("%s", wdArr[i]);
	}
	fprintf(fp2, "-----------------------------------\n");
	for(int i=0; i<MAXNUM; i++)
	{
		free(wdArr[i]);
	}
	free(wdArr);
	free(numArr);
	fclose(fp);
	fclose(fp2);
	return 0;
}
