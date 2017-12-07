#include<stdlib.h>
#include<time.h>
void horizonset(int **MAP,int line)
{
	int i, j,r,cnt=0;
	int prev=0,cur=0;
	srand(time(NULL));
	for (i = 1; i < 21; i++)
	{
		for (j = 1; j < line-1; j+=2)
		{
			r=rand()%2;
			prev=cur;
			cur=r;
			if(r==0&&prev!=0)
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

void verticalset(int **MAP,int line,int h,int num)
{
	int i, j;
	i=0;
	int cnt=0;
	//첫째줄 인원
	for(j=0;j<line-1;j++)
	{
		
		if(j%2==0)
		{
			MAP[i][j] =65+cnt;
			cnt++;
		}
		else MAP[i][j] = ' ';
	}
	//사다리
	for (i = 1; i < 21; i++)
	{
		for (j = 0; j < line-1; j++)
		{
			
			if (j % 2 == 0) MAP[i][j] = '|';
			else MAP[i][j] = ' ';
		}
	}
	//마지막줄 당첨여부
	srand(time(NULL));
	int *boomb=(int*)malloc(sizeof(int) *(h));
	
	for(int i=0;i<num;i++)
	{
		boomb[i]='F';//Fail
	}
	for(int i=num;i<h;i++)
	{
		boomb[i]='P';//PASS
	}
	/*
	for(int i=0;i<h;i++)
	{
		printf("%c",boomb[i]);
	}
	printf("\n");
	*/
	int nDust,nSour,nTemp;
	srand(time(NULL));
	for(int i=0;i<100;i++)
	{
		nDust = rand()%h;
		nSour = rand()%h;

		nTemp = boomb[nDust];
		boomb[nDust] = boomb[nSour];
		boomb[nSour] = nTemp;
	}
	/*
	for(int i=0;i<h;i++)
	{
		printf("%c",boomb[i]);
	}
	printf("\n");
	*/
	//당첨여부 넣기
	cnt=0;
	for(j=0;j<line-1;j++)
	{	
		if(j%2==0)
		{
			MAP[21][j] =boomb[cnt];
			cnt++;
		}
		else MAP[21][j] = ' ';
	}
	free(boomb);
		
}


