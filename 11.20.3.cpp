#include <stdio.h>
#include <stdlib.h>
void zhuanzhi(int a[3][3]);
int main()
{
	int a[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
			
		}
	}
	zhuanzhi(a);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}


void zhuanzhi(int a[][3])
{   int m;
	for(int i=0;i<3;i++)
	{   int j=i;
		for(;j<3;j++)
		{m=a[i][j];
		 a[i][j]=a[j][i];
		 a[j][i]=m;
		 
			
}
}
}
