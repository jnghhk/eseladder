#include<stdio.h>
#include"printColorString.h"
void printmap(int **MAP,int line)
{
	char buf[128]={0,};
	int i, j;
	for (i = 0; i < 22; i++)
	{
		for (j = 0; j < line-1; j++)
		{
			sprintf(buf,"%c",MAP[i][j]);
			if(j%2==0)	printColorString(1,buf);
			else	printColorString(1,buf);
		}
		printf("\n");
	}
}

