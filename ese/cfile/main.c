#include<stdio.h>
#include"gotoxy.h"
#include"horizonset.h"
#include"verticalset.h"
#include"start.h"
#include"printColorString.h"

int main()
{
	int **MAP;
	int line;
	int h;
	int num;

	system("clear");
	printf("인원수:");
	scanf("%d", &line);
	printf("(F:FAIL P:PASS)꽝 개수:");
	scanf("%d",&num);
	system("clear");
	h=line;
	line = line*2;
	int col = 22;
	MAP = (int **)malloc(sizeof(int*)*col);
	for (int i = 0; i < col; i++)
	{
		MAP[i] = malloc(sizeof(int) *(line-1));
	}
	verticalset(MAP,line,h,num);
	horizonset(MAP,line);
	printmap(MAP,line);
	start(MAP,line);

	
	for (int k = 0; k < 22; k++)
	{
		free(MAP[k]);
	}
	free(MAP);
	gotoxy(0,30);
	return 0;

}
