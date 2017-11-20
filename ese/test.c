#include<stdio.h>
#include<stdlib.h>

int line;
void verticalset(int (*MAP)[20])
{
  int i,j;
   for(i=0;i<line;i++)
   {
       for(j=0;j<20;j++)
       {
           MAP[j][i]=j;
       }
   } 
}

int main()
{
   scanf("%d",&line);
   int MAP[line][20];
   int i,j;
   verticalset(MAP);   
   for(i=0;i<line;i++)
   {
      for(j=0;j<20;j++)
      {
         printf("%d ",MAP[j][i]);
      }
      printf("\n");
   }
   

return 0;
}
