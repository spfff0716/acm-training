#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
struct node
{
	int u,v;
	long long w;
};
int fi[N];
int cnt[N];
int find(int x)
{
	if(fi[x]!=x)
	fi[x]=find(fi[x]);
	return fi[x];
}
bool cmp(node x,node y)
{
	return x.w>y.w;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		fi[i]=i;
		cnt[i]=0;
	}
	for(int i=0;i<k;i++)
	{
		int d;
		cin>>d;
		cnt[d]=1;
	}
	vector<node>arr;
	long long sum=0;
	long long left=0;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		long long c;
		cin>>a>>b>>c;
		sum+=c;
		arr.push_back({a,b,c});
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<arr.size();i++)
	{
		int x=arr[i].u;
		int y=arr[i].v;
		int cost=arr[i].w;
		int nx=find(x);
		int ny=find(y);
		if(nx!=ny)
		{
			if(cnt[nx]+cnt[ny]<=1)
			{
				fi[nx]=ny;
				cnt[ny]+=nx;
				left+=cost;
			}
		}
	}
	cout<<sum-left;
	return 0;
 } 
