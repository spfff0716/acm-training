#include <stdio.h>
#include <stdlib.h>
int strcmp(const char *s1,const char *s2);
int main()
{
	char str1[1000];
	char str2[1000];
	scanf("%s",str1);
	scanf("%s",str2);
	int m=strcmp(str1,str2);
	printf("%d",m);
	return 0;
	
}

int strcmp(const char *s1,const char *s2)
{
	while(*s1==*s2)
	{
		if(*s1=='\0')
		return 0;
		s1++;
		s2++;
		
	}
	return *s1-*s2;
}
