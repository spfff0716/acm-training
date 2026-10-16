#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e3+10;
struct node
{
	int x,y,t;
}road[N];
int fa[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int find(int x)
{
	if(fa[x]!=x)
	fa[x]=find(fa[x]);
	return fa[x];
}
bool merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
	return true;
	fa[fx]=fy;
	return false;
}
bool cmp(node x,node y)
{
	return x.t<y.t;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>road[i].x>>road[i].y>>road[i].t;
	}
	init();
	sort(road,road+m,cmp);
	int res=0;
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		int u=road[i].x;
		int v=road[i].y;
		int need=road[i].t;
		if(merge(u,v))
		continue;
		else
		{
			cnt++;
			res=need;
		}
		if(cnt==n-1)
		break;
	}
	if(cnt<n-1)
	cout<<-1;
	else
	cout<<res;
	return 0;
}
