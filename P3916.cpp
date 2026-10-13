#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int fi[N];
int find(int x)
{
	if(fi[x]==x)
	return x;
	fi[x]=find(fi[x]);
	return fi[x];
}
void combine(int x,int y)
{
	int nx=find(x);
	int ny=find(y);
	if(nx!=ny)
	{
		if(nx>ny)
		fi[ny]=nx;
		else
		fi[nx]=ny;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fi[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		combine(u,v);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<fi[i]<<" ";
	}
	return 0;
}
