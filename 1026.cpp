#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int x,n;
	scanf("%d %d",&x,&n);
	double p0=1.0;
	double p1=(double)x;
	 double a=p1;
	 double b=p0;
	 double pn=1;
	 int i=2;
	 
	if(n==0)
	{
	printf("%.6f",p0);
	return 0;
	}
	
	if(n==1)
	{
	printf("%.6f",p1);
	return 0;}
	
	
		 while(i<=n)
	 	{
		 
	 	pn=((2*i-1)*x*a-(i-1)*b)/i;
	 	b=a;
	 	a=pn;
	 	
		 i++;}
	 	printf("%.6f",pn);
	 
	 
	
	return 0;
}
