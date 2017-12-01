#ifndef STARTPRINT_H
#define STARTPRINT_H
#include<stdio.h>
#include"printmap.h"
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

#endif