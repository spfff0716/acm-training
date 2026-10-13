#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	scanf("%d",&a);
	int b=1;
	
	while(b*10<=a)
	b=b*10;
	printf("%d",a-b);
	return 0;
 } 
