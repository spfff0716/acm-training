#include<stdio.h>
#include <stdlib.h>
int main()
{
	int a[3];
	int *p[3]={&a[0],&a[1],a+2};
	int *replace;
	for (int i = 0; i < 3; ++i)
        scanf("%d", p[i]);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3-i-1;j++)
		{if(*p[j]>*p[j+1])
		{replace=p[j];
		 p[j]=p[j+1];
		 p[j+1]=replace;
		}
		}
	}
	for(int i=0;i<3;i++)
	printf("%d",*p[i]);
	return 0;
	
}
