#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10
#define MAXLEN 11

int main()
{
	int r, j=0;
	char line[MAXLEN];
	FILE *fp;
	fp = fopen("dataset1.txt", "w+");

	srand(0);
	for(int i=0; i<MAXNUM; i++)
	{
		fprintf(fp, "%d\n", rand());
	}
	fclose(fp);

	fp = fopen("dataset2.txt", "w+");
	for(int i=0; i<MAXNUM; i++)
	{
		for(j=0; j<MAXLEN; j++)
		{
			r = rand()%2;
			if(r) line[j] = (rand()%26 + 65);
			else line[j] = (rand()%26 + 97);
		}
		line[j] = '\0';
		fprintf(fp, "%s\n", line);
	}
	fclose(fp);
}
