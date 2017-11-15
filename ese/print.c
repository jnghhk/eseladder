#include<stdio.h>
int main()
{
   char ladder;
   ladder='@';
   int i;
   for(i=0;i<10;i++){
   printf("%c",ladder);
   if(i%5==0) printf("\n");
}
   return 0;
}
