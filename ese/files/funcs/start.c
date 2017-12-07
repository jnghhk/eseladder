
#include<stdio.h>
#include<unistd.h>
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

void startprint(int l,int i,int j,int **MAP)
{
	char buf[128]={0,};
	gotoxy(j+1,i+1);
	sprintf(buf,"%c",MAP[i][j]);
	printColorString(30+l,buf);
	usleep(80000);
}
void start(int **MAP,int line)
{
	int i=0;
	int j,l;
//	gotoxy(0,2);//
	for(l=0;l<line-1;l+=2)
	{
		i=1;
		j=l;
		startprint(l,i-1,j,MAP);
		while(1)
		{			
			startprint(l,i,j,MAP);
			if(MAP[i][j]=='|' && MAP[i][j+1]=='-')
			{
				j+=1;
				startprint(l,i,j,MAP);
				j+=1;
				startprint(l,i,j,MAP);
			}
			else if(MAP[i][j]=='|' && MAP[i][j-1]=='-')
			{
				j-=1;
				startprint(l,i,j,MAP);
				j-=1;
				startprint(l,i,j,MAP);
			}
			i++;
			if(MAP[i][j]=='F'||MAP[i][j]=='P') break;
		}
			startprint(l,i,j,MAP);
		
	}
}

