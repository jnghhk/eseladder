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

