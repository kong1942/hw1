#include "sort.h"

int main(int argc, char **argv)
{
	if(argc != 3) exit(0);
	FILE *fp;
	char testline[MAXLEN];
	char **wdArr;
	wdArr = (char **)malloc(sizeof(char *) * MAXNUM);
	for(int i=0; i<MAXNUM; i++)
	{
		wdArr[i] = (char *)malloc(sizeof(char) * MAXLEN);
	}
	int *numArr;
	numArr = (int *)malloc(sizeof(int) * MAXNUM);
	int num=0, wd=0, i=1;
	memset(numArr, 0, MAXNUM*sizeof(int));

	if(!strcmp(argv[2], "n")) fp = fopen("dataset1.txt", "r");
	else if(!strcmp(argv[2], "w")) fp = fopen("dataset2.txt", "r");

	if(fgets(testline, MAXLEN, fp))
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
		
		while(fscanf(fp, "%d", ptr) && ptr - numArr < MAXNUM) { ptr++; }
		ptr = numArr;
		if(!strcmp(argv[1], "qk")) 
		{
			qksort(numArr, 0, MAXNUM);
		}

		else 
		{
			int *numArr2;
			numArr2 = (int *)malloc(sizeof(int) * MAXNUM);
			memset(numArr2, 0, MAXNUM*sizeof(int));
			
			if(!strcmp(argv[1], "mg")) 
			{
				mgsort(numArr, numArr2, 0, MAXNUM-1);
			}
			else if(!strcmp(argv[1], "rd")) 
			{
				rdsort(numArr, numArr2);
			}
			free(numArr2);
		}

		while(ptr - numArr < MAXNUM) { printf("%d\n", *ptr); ptr++; }
	}
	
	else if(wd)
	{
		while(fgets(wdArr[i], MAXLEN, fp)) { i++; }
		if(!strcmp(argv[1], "qk"))
		{
			qksort2(wdArr, 0, i);
		}
		else 
		{
			char **wdArr2;
			wdArr2 = (char **)malloc(sizeof(char *) * MAXNUM);
			for(int i=0; i<MAXNUM; i++)
			{
				wdArr2[i] = (char *)malloc(sizeof(char) * MAXLEN);
			}
			
			if(!strcmp(argv[1], "mg"))
			{
				mgsort2(wdArr, wdArr2, 0, MAXNUM-1);
			}
			else if(!strcmp(argv[1], "rd"))
			{
				rdsort2(wdArr, wdArr2);
			}
			for(int i=0; i<MAXNUM; i++)
			{
				free(wdArr2[i]);
			}
			free(wdArr2);
		}
		for(int i=0; i<MAXNUM; i++) printf("%s", wdArr[i]);
	}

	for(int i=0; i<MAXNUM; i++)
	{
		free(wdArr[i]);
	}
	free(wdArr);
	free(numArr);
	fclose(fp);
	return 0;
}
