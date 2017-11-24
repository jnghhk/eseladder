#include<stdio.h>
#include<stdlib.h>

int line;
int **MAP;

void verticalset()
{
	int i, j;
	for (i = 0; i < 22; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (j % 2 == 0) MAP[i][j] = '#';
			else MAP[i][j] = ' ';
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
		MAP[i] = malloc(sizeof(int) *line);
	}
	verticalset(MAP);
	int i, j;
	for (i = 0; i < 22; i++)
	{
		for (j = 0; j < line; j++)

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
	return 0;

}

