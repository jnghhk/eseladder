#include<stdio.h>
int line;
void verticalLine(int map[20][line])
{
   int i,j;
   line=line*4;
   for(i=0;i<20;i++){
      for(j=0;j<line;j++){
         if(j%4==0){
         map[i][j]='*';  }
         else{
         map[i][j]=' ';  }
      }
   }   
}


int main()
{
int MAP[20][line];
scanf("사람수 입력:%d",&line);
verticalLine(MAP);
return 0;
}
