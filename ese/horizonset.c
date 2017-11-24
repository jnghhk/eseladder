#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int line;
int **MAP;
void verticalset()
{
	int i, j;
	for (i = 0; i < 22; i++)
	{
		for (j = 0; j < line-1; j++)
		{
			if (j % 2 == 0) MAP[i][j] = '|';
			else MAP[i][j] = ' ';
		}
	}
}
void horizonset()
{
	int i, j,r,cnt=0;
	srand(time(NULL));
	for (i = 0; i < 22; i++)
	{
		for (j = 1; j < line-1; j+=2)
		{
			r=rand()%3;
			if(r==0)
			{
				int a=(22*(line-1))/3;
				if(cnt==a)
				{
					return;
				}
				MAP[i][j]='-';
				cnt++;
			}
		}
	}

}

int main()
{
	printf("인원수");
	scanf("%d", &line);
	line = line*2;
	int col = 22;
	MAP = (int **)malloc(sizeof(int*)*col);
	for (int i = 0; i < col; i++)
	{
		MAP[i] = malloc(sizeof(int) *(line-1));
	}
	verticalset();
	horizonset();

	int i, j;
	for (i = 0; i < 22; i++)
	{
		for (j = 0; j < line-1; j++)
		{
			printf("%c", MAP[i][j]);
		}
		printf("\n");
	}
	for (int k = 0; k < 22; k++)
	{
		free(MAP[k]);
	}
	free(MAP);
	//srand((unsigned)time(NULL));
	//printf("%d",rand()%4);
	
	return 0;

}
