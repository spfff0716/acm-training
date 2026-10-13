#include <stdio.h>
#include <stdlib.h>
double f(int n);
int main()
{
	int n;
	scanf("%d",&n);
	double m=f(n);
	printf("%.2f",m);
	return 0;
	
	
 } 
double f(int n)
{
	if(n==1)
	return 1.0;
	if(n==2)
	return 1.0;
	int a=1.0,b=1.0;
	double m;
	for(int i=2;i<n;i++)
	{
		m=a+b;
		a=b;
		b=m;
	}
	return m;
	
	
}
