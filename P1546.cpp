#include <bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
}tree[10005];
int fi[105];
int find(int x)
{
	if(fi[x]==x)
	return x;
	fi[x]=find(fi[x]);
	return fi[x];
}
bool combine(int x,int y)
{
	int nx=find(x);
	int ny=find(y);
	if(nx==ny)
	return true;
	fi[nx]=ny;
	return false;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		fi[i]=i;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			if(j>i)
			{
				tree[cnt].u=i;
				tree[cnt].v=j;
				tree[cnt].w=x;
				cnt++;
			}
		}
	}
	sort(tree,tree+cnt,cmp);
	int ans=0;
	int c=0;
	for(int i=0;i<cnt;i++)
	{
		int x=tree[i].u;
		int y=tree[i].v;
		int z=tree[i].w;
		if(combine(x,y))
		continue;
		ans+=z;
		c++;
		if(c==n-1)
		break;
	}
	cout<<ans;
	return 0;
 } 
