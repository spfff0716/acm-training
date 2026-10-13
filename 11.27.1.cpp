#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int max=0;
	int min=10;
	double sum=0.0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum=a[i]+sum;
		if(a[i]>max)
		max=a[i];
		if(a[i]<min)
		min=a[i];
	}
	sum=sum-max-min;
	n=n-2;
	printf("%.2f",sum/n);
	return 0;
	
}


