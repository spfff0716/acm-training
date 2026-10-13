#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[110];
	int cnt=0;
	while(scanf("%d",&a[cnt])) 
	{
		if(a[cnt]==0)
		break;
		cnt++;
	}
	a[cnt]='\0';
	for(int i=cnt-1;i>=0;i--)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
