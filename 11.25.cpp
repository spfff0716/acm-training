#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	int x;
	scanf("%d %d",&n,&x);
	int j=1;
	int cnt=0;
	int m,num;
	for(int i;i<=n;i++)
	{
		num=i;
		for(;;)
		{
			m=num%10;
			if(x==m)
			cnt++;
			if(num<10)
			break;
			num=num/10;
			
			
		}}
		printf("%d",cnt);
		return 0;
	}
	

