#include <stdio.h>
#include <stdlib.h>
int isprime(int n);
int ishuiwen(int n);
int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=1;i<=b;i++)
	{
		if(i<a)
		continue;
		if(isprime(i)&&ishuiwen(i))
		{
			printf("%d\n",i);
		}
	}
	
	
	return 0;
	
 } 
 
 
 
int isprime(int n)
{
	if(n<2)
	return 0;
	else if(n==2)
	return 1;
	
	
		for(int i=2;i<n;i++)
		{
			if(n%i==0)
			
			return 0;
			
			
		}
	return 1;
	
}


int ishuiwen(int n)
{
	int replace,t;
	replace=0;
	t=n;
	while(n)
	{
		replace=10*replace+n%10;
		n=n/10;
	}
	if(replace==t)
	return 1;
	return 0;
	
}
