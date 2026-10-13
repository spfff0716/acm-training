#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[10000]={0},b[10000]={0},c[11000]={0};
	
	string x,y;
	cin>>x>>y;
	int la=x.size();
	int lb=y.size();
	int lc=la+lb-2;
	for(int i=0;i<la;i++)
	{
		a[la-1-i]=x[i]-'0';
	}
	for(int i=0;i<lb;i++)
	{
		b[lb-1-i]=y[i]-'0';
	}
	for(int i=0;i<la;i++)
	{
		for(int j=0;j<lb;j++)
		{
			c[i+j]=a[i]*b[j];
		}
	}
	for(int i=0;i<lc;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10; 
	}
	while(c[lc])
	lc++;
	for(int i=lc-1;i>=0;i--)
	{
		cout<<c[i];
	}
	return 0;
}
