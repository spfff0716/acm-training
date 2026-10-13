#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool canbuild(int n,int m,vector<vector<ll>>need)
{
	vector<ll>remain(n+2,0);
	for(int sum=2;sum<n+m;sum++)
	{
		int nowl=max(1,sum-m);
		int nowr=min(n,sum-1);
		int nextl=max(1,sum-m+1);
		int nextr=min(n,sum);
		for(int i=nowl;i<=nowr;i++)
		{
			int j=sum-i;
			remain[i]=need[i][j];
		}
		for(int i=nextl;i<=nextr;i++)
		{
			int j=sum+1-i;
			ll target=need[i][j];
			ll force=0;
			if(i-1>=nowl&&i-1<=nowr)
			{
				force=remain[i-1];
			}
			if(force>target)
			{
				return false;
			}
			ll left=target-force;
			ll avail=0;
			if(i>=nowl&&i<=nowr)
			{
				avail=remain[i];
			}
			if(avail<left)
			{
				return false;
			}
			if(i-1>=nowl&&i-1<=nowr)
			{
				remain[i-1]=0;
			}
			if(i>=nowl&&i-1<=nowr)
			{
				remain[i]-=left;
			}
		}
		for(int i=nowl;i<=nowr;i++)
		{
			if(remain[i]!=0)
			return false;
		}
	}
	return true;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<ll>>arr(n+1,vector<ll>(m+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>arr[i][j];
		}
	}
	if(n==1||m==1)
	{
		bool flag=true;
		ll v=arr[1][1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(arr[i][j]!=v)
				{
					flag=false;
				}
			}
		}
		if(flag)
		{
			cout<<0<<'\n';
		}
		else
		{
			cout<<-1<<'\n';
		}
		return;
	}
	if(arr[n][m]!=arr[1][1])
	{
		cout<<-1<<'\n';
		return;
	}
	ll ways=arr[1][2]+arr[2][1]-2*arr[1][1];
	if(ways<0)
	{
		cout<<"-1"<<'\n';
		return;
	}
	ll last=arr[1][1]+ways;
	bool flag1=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ll cnt=last-arr[i][j];
			if(cnt<0||cnt>ways)
			{
				flag1=false;
				break;
			}
			arr[i][j]=cnt;
		}
	}
	if(!flag1)
	{
		cout<<-1<<'\n';
		return;
	}
	if(!canbuild(n,m,arr))
	{
		cout<<-1<<'\n';
		return;
	}
	else
	{
		cout<<ways<<'\n';
		return;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
