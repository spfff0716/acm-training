#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int fa[N];
struct node
{
	int u,v,cost;
};
int find(int x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
bool uni(int x,int y)
{
	int nx=find(x);
	int ny=find(y);
	if(nx!=ny)
	{
		fa[nx]=ny;
		return true;
	}
	return false;
}
bool cmp(node x,node y)
{
	return x.cost<y.cost;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	vector<node>brr;
	for(int i=0;i<m;i++)
	{
		int x,y,l;
		cin>>x>>y>>l;
		brr.push_back({x,y,l});
	}
	sort(brr.begin(),brr.end(),cmp);
	int ans=0;
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		if(cnt==n-k)
		break;
		int x=brr[i].u;
		int y=brr[i].v;
		int l=brr[i].cost;
		if(uni(x,y))
		{
			ans+=l;
			cnt++;
		}
	}
	if(cnt==n-k)
	cout<<ans;
	else
	cout<<"No Answer";
	return 0;
 } 
