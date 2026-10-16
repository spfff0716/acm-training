#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10; 
struct node
{
	int d,s,t;
};
int r[N];
node arr[N];
int n,m;
int cha[N];
bool check(int k)
{
	memset(cha,0,sizeof(cha));
	for(int i=1;i<=k;i++)
	{
		int d=arr[i].d;
		int s=arr[i].s;
		int t=arr[i].t;
		cha[s]+=d;
		cha[t+1]-=d;
	}
	for(int i=1;i<=n;i++)
	{
		cha[i]=cha[i]+cha[i-1];
		if(cha[i]>r[i])
		return true;
	 } 
	return false;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>arr[i].d>>arr[i].s>>arr[i].t;
	}
	//找最小不可行的位置
	int l=1;
	int r=1e6+10;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	 }
	if(l>m)
	cout<<0;
	else
	cout<<-1<<endl<<l;
	return 0;
}
