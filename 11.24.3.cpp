#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int hour,minute;
	if(b>d)
    {
    	hour=c-a-1;
    	minute=d+60-b;
	}
	else
	{
		hour=c-a;
		minute=d-b;
	}
	printf("%02d %02d",hour,minute);
	
	return 0;
}
