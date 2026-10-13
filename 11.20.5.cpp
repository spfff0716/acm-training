#include <stdio.h>
#include <stdlib.h>
int fun(char *a,int n);
int main()
{    int cnt=0;
	char a[1000];
	scanf("%s",a);
	while(a[cnt])
	cnt++;
	int n=fun(a,cnt);
	if(n==0)
	printf("NO");
	else
	printf("YES");
	return 0;
	
}
int fun(char *a,int n)
{   int m;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[n-i])
		{
			m=1;
		}
		else
		{
			m=0;
			break;
		}
	}
	return m;
}
