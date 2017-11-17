#include<stdio.h>
int line;
void printLine(int map[20][line])
{
   int i,j;
   for(i=0;i<20;i++){
      for(j=0;j<line;j++){
         printf("%c",map[i]][j]);
      }
      printf("\n");
    }
   printf("\n");
      
}


int main()
{
int MAP[20][line];
scanf("사람수 입력:%d",&line);
verticalLine(MAP);
printLine(MAP);
return 0;
}
