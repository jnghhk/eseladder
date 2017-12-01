#ifndef GOTOXY_H
#define GOTOXY_H
#include<stdio.h>
void gotoxy(int x, int y) 
{
     printf("\033[%d;%df",y,x);
     fflush(stdout);
}

#endif