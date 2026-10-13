#include <stdio.h>
#include <stdlib.h>
int search(char key,char a[],int n);
int M(char a[],int n);
int main()
{
	char *a=NULL;
	int cap=0;
	int cnt=0;
	char x;
	while(scanf(" %c",&x)==1)
	{
		if(cnt==cap)
		{cap=(cap+1)*2;
		a=(char*)realloc(a,cap * sizeof *a);
		if(!a) return 0;
	}
	a[cnt++]=x;}
	char key;
	key=M(a,cnt);
	int number;
	number=search(key,a,cnt);
	printf("%d",number);
	return 0;
	
	
	
	
}

search(char key,char a[],int n)
{
	int m=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==key)
		m+=1;
	}
	return m;
}

M(char a[],int n)
{
	
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
		}
		return max;
		
	}
	

