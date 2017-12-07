#include<stdio.h>
int main()
{
	int i=0,j=0;
	for(i=0;i<10;i++)
	{
		j=i;
		while(1)
		{
			if(j==5) break;
			printf("%d\n",j);
			j++;
		}
	}
	return 0;
}