#include <bits/stdc++.h>
using namespace std;
int f[20];
struct node
{
	int v;
	int u;
	double w;
};
struct point
{
	double x;
	double y;
	int id;
};
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]!=x)
	{
		f[x]=find(f[x]);
	}
	return f[x];
}
bool uni(int x,int y)
{
	int nx=find(x);
	int ny=find(y);
	if(nx!=ny)
	{
		f[nx]=ny;
		return true;
	}
	else
	return false;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		f[i]=i;
	}
	vector<node>brr;
	vector<point>p;
	p.push_back({0,0,0});
	for(int i=1;i<=n;i++)
	{
		double nx,ny;
		cin>>nx>>ny;
		for(auto &it:p)
		{
			double value=sqrt((it.x-nx)*(it.x-nx)+(it.y-ny)*(it.y-ny));
			brr.push_back({it.id,i,value});
		}
		p.push_back({nx,ny,i});
	}
	sort(brr.begin(),brr.end(),cmp);
	int cnt=0;
	double ans=0;
	for(auto &it:brr)
	{
		if(uni(it.u,it.v))
		{
			cnt++;
			ans+=it.w;
		}
		if(cnt==n)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
 } 
