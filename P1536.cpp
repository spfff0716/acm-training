#include <bits/stdc++.h>
using namespace std;
int fa[1010];
int find(int x)
{
	if(fa[x]==x)
	return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void combine(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	fa[fx]=fy;
}
int main()
{
	int n,m;
	while(true)
	{
	cin>>n;
	if(n==0)
	return 0;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		combine(x,y);
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i)
		res++;
	}
	cout<<res-1<<endl;
	}
	return 0;
 } 
