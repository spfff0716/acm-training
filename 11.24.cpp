#include <stdio.h>
int main()
{
	for(int j=1;j<=5;j+=2)
	{   for(int k=1;k<=((5-j)/2);k++)
	     printf(" ");
		for(int i=1;i<=j;i++)
		
		printf("*");
		printf("\n");
		
	}
	for(int j=3;j>=1;j-=2)
	{   for(int k=1;k<=((5-j)/2);k++)
	    printf(" ");
		for(int i=1;i<=j;i++)
		printf("*");
		printf("\n");
		
	}
	return 0;
	
}
