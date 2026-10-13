#include <stdio.h>
#include <iostream>
int main()
{
	int n,q;
	long back[n][5e+10];
	cin>>n>>q;
	long buf[5]={0};
	for(int i=0;i<q;i++)
	{
		int cnt=0
		while(cnt<5&&scanf("%d",&buf[cnt])==1)
		cnt++;
		i=buf[1];
		j=buf[2];
		if(buf[0]==1)
		{
			back[i][j]=buf[3];
		}
		if(buf[0]==2)
		cout<<back[i][j];
		putchar('\n');
		
		
	}
	return 0;
	
}
