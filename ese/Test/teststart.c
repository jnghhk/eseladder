#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>//sleep


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
void horizonset(int **MAP,int line)
{
	int i, j,r,cnt=0;
	int prev=0,cur=0;
	srand(time(NULL));
	for (i = 1; i < 21; i++)
	{
		for (j = 1; j < line-1; j+=2)
		{
			r=rand()%3;
			prev=cur;
			cur=r;
			if(r==0&&prev!=0)
			{
				int a=(22*(line-1))/4;
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
void gotoxy(int x, int y) 
{
     printf("\033[%d;%df",y,x);
     fflush(stdout);
}
void printColorString(int color, char * str) 
{
	printf("\033[%dm%s\033[0m", color, str);
	/*
	0 : 모든 색과 스타일 초기화
1 : 굵게(bold) / 밝게
3 : 이탤릭체(italic)
4 : 밑줄(underline)
7 : 반전(글자색/배경색을 거꾸로)
9 : 가로줄 치기
22 : 굵게(bold) 제거
23 : 이탤릭체(italic)제거
24 : 밑줄(underline)제거
27 : 반전 제거
29 : 가로줄 제거
30 : 글자색:검정
31 : 글자색:빨강
32 : 글자색:초록
33 : 글자색:노랑
34 : 글자색:파랑
35 : 글자색:마젠트(분홍)
36 : 글자색:시안(청록)
37 : 글자색:백색
39 : 글자색으로 기본값으로
40 : 바탕색:흑색
41 : 바탕색:적색
42 : 바탕색:녹색
43 : 바탕색:황색
44 : 바탕색:청색
45 : 바탕색:분홍색
46 : 바탕색:청록색
47 : 바탕색:흰색
49 : 바탕색을 기본값으로
*/
}
void print(int **MAP,int line)
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

void start(int **MAP,int line)
{
	gotoxy(0,29);
	printf("start");
	char buf[128]={0,};

	int i=0;
	int j,l;
//	gotoxy(0,2);//
	for(l=0;l<line-1;l+=2)
	{
		gotoxy(0,29);
		i=1;
		j=l;
		while(1)
		{
			gotoxy(j+1,i+1);
			sprintf(buf,"%c",MAP[i][j]);
			printColorString(45,buf);
			sleep(1);
			if(MAP[i][j]=='|' && MAP[i][j+1]=='-')
			{
				j+=1;
				gotoxy(j+1,i+1);
				sprintf(buf,"%c",MAP[i][j]);
				printColorString(45,buf);
				j+=1;				
			}
			else if(MAP[i][j]=='|' && MAP[i][j-1]=='-')
			{
				j-=1;
				gotoxy(j+1,i+1);
				sprintf(buf,"%c",MAP[i][j]);
				printColorString(45,buf);
				j-=1;
			}

		//	else
			//{
				i++;
			//}
			if(MAP[i][j]=='F'||MAP[i][j]=='P') break;
		}
		
	}
}

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
	print(MAP,line);
	start(MAP,line);

	
	for (int k = 0; k < 22; k++)
	{
		free(MAP[k]);
	}
	free(MAP);
	gotoxy(0,30);
	return 0;

}
