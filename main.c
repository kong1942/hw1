#include "sort.h"

int main(int argc, char **argv)
{
	if(argc != 2) exit(0);
	char wdArr[MAXNUM][MAXLEN];
	char wdArr2[MAXNUM][MAXLEN];
	int numArr[MAXNUM];
	int numArr2[MAXNUM];
	char testline[MAXLINELEN];
	int num=0, wd=0, i=1;

	memset(numArr, 0, MAXNUM*sizeof(int));
	memset(numArr2, 0, MAXNUM*sizeof(int));

	if(fgets(testline, MAXLINELEN, stdin))
	{
		if(isdigit(*testline)) 
		{
			numArr[0] = atoi(testline);
			num++;
		}
		else if(isalpha(*testline))
		{
			strcpy(wdArr[0], testline);
			wd++;
		}
	}

	if(num)
	{
		int *ptr = &numArr[1];
		while(scanf("%d", ptr) && ptr - numArr < MAXNUM) { ptr++; }
		ptr = numArr;
		if(!strcmp(argv[1], "qk")) qksort(numArr, 0, MAXNUM);
		if(!strcmp(argv[1], "mg")) mgsort(numArr, numArr2, 0, MAXNUM-1);
		if(!strcmp(argv[1], "rd")) ptr = rdsort(numArr, numArr2);
		if(!strcmp(argv[1], "hp")) hpsort(numArr);
		while(ptr - numArr < MAXNUM) { printf("%d\n", *ptr); ptr++; }
	}
	/*
	else if(wd)
	{
		while(fgets(wdArr[i], MAXLEN, stdin)) { i++; }
		if(!strcmp(argv[1], "qk")) qksort(wdArr[i], 0, i);
	}
	*/
	return 0;
}
