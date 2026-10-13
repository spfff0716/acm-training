# include<stdio.h>
# include<stdlib.h>
int main()
{
	char a;
	char *n=&a;
	int cnt=0;
	while(scanf("%c",n)==1)
	cnt++;
	printf("%d",cnt);
	return 0;
}
