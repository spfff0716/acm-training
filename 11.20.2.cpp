# include<stdio.h>
# include<stdlib.h>
int main()
{
	char a;
	char *n=&a;
	int cnt=0;
	while(scanf("%s",n)==1)
	cnt++;
	return 0;
}
