#include<stdio.h>
#include<stdlib.h>
#include"mapset.h"
#include"start.h"
void horizonset(int **MAP,int line);
void verticalset(int **MAP,int line,int h,int num);
void gotoxy(int x,int y);
void printColorString(int color ,char *str);
void printmap(int **MAP,int line);
void startprint(int l,int i,int j,int **MAP);
void start(int **MAP,int line);

int main()
{
	int **MAP;
	int line;
	int h;
	int num;

	system("clear");
	printf("인원수:");
	scanf("%d", &line);
	while(line<=1 || line>10)
	{
		printf("인원수는 최소 2,최대 10명입니다.");
		printf("인원수:");
		scanf("%d", &line);
	}
	printf("(F:FAIL P:PASS)꽝 개수:");
	scanf("%d",&num);
	while(num<1 || num >= line)
	{
		printf("꽝개수1~%d",line-1);
		printf("(F:FAIL P:PASS)꽝 개수:");
		scanf("%d",&num);
	}
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
