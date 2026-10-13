#include <bits/stdc++.h>
using namespace std;
const int M=2*1e5+10;
const int N=5005;
int fi[N];
struct node
{
	int u,v,w;
}tree[M];
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
	fi[nx]=fi[ny];
	return false;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fi[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		cin>>tree[i].u>>tree[i].v>>tree[i].w;
	}
	sort(tree,tree+m,cmp);
	int cnt=0;
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int x=tree[i].u;
		int y=tree[i].v;
		int z=tree[i].w;
		if(combine(x,y))
		continue;
		ans+=z;
		cnt++;
		if(cnt==n-1)
		break;
	}
	if(cnt==n-1)
	{
		cout<<ans;
	}
	else
	cout<<"orz";
	return 0;
 } 
