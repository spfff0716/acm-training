#include <bits/stdc++.h>
using namespace std;
int n;
int fi[305];
int find(int x)
{
	if(fi[x]!=x)
	fi[x]=find(fi[x]);
	return fi[x];
}
bool uni(int x,int y)
{
	int nx=find(x);
	int ny=find(y);
	if(nx!=ny)
	{
		fi[nx]=ny;
		return true;
	}
	return false;
}
struct node
{
	int u,v,cost;
};
bool cmp(node x,node y)
{
	return x.cost<y.cost;
}
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		fi[i]=i;
	}
	vector<node>brr;
	int w;
	for(int i=1;i<=n;i++)
	{
		cin>>w;
		brr.push_back({0,i,w});
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>w;
			if(j>i)
			{
				brr.push_back({i,j,w});
			}
		}
	}
	sort(brr.begin(),brr.end(),cmp);
	int cnt=0;
	int ans=0;
	for(int i=0;i<brr.size();i++)
	{
		if(uni(brr[i].u,brr[i].v))
		{
			ans+=brr[i].cost;
			cnt++;
		}
		if(cnt==n)
		break;
	}
	cout<<ans;
	return 0;
	
}
