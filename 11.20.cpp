#include <stdio.h>
#include <stdlib.h>
int input(int a[]);
int replace(int a[]);
int output(int a[]) ;

int input(int a[])
{
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	return 0;
}
int replace(int a[])
{
	int max=a[0];
	int num=0;
	for(int i=0;i<10;i++)
	{
		if(max<a[i])
		{max=a[i];
		 num=i;
		}
		
	}
    int min=a[0];
    int n=0;
		for(int j=0;j<10;j++)
	{
		if(min>a[j])
		{min=a[j];
		 n=j;
		}
		
	}
	int m;
	m=a[9];
	a[9]=a[num];
	a[num]=m;
	m=a[0];
	a[0]=a[n];
	a[n]=m;
	return 0;
}
int output(int a[])
{   printf("%d",a[0]);
	for(int i=1;i<10;i++)
	printf(" %d",a[i]);
	return 0;
}
int main()
{
	int a[10];
	input(a);
	replace(a);
	output(a);
	return 0;
	 
}
