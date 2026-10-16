#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii=pair<int,int>;
const int N=110;
int n,q;
vector<pii>g[N];
int dp[N][N];
int dfs(int u,int fa)
{
	bool noleaf=true;
	int cnt=0;
	int cnt1=0;
	int cnt2=0;
	int v1,w1,v2,w2;
	for(auto &it:g[u])
	{
		int v=it.first;
		int val=it.second;
		if(v==fa)
		continue;
		else
		{
			if(cnt1!=0)
			{
				cnt++;
				cnt2=dfs(v,u);
				v2=v;
				w2=val;
			}
			else
			{
				cnt++;
				cnt1=1+dfs(v,u);
				v1=v;
				w1=val;
			}
			noleaf=false;
		}
	}
	cnt=cnt+cnt1+cnt2;
	if(noleaf)
	{
		dp[u][0]=0;
		return 0;
	}
	for(int fir=0;fir<=cnt;fir++)
	{
		for(int sec=0;sec<=cnt;sec++)
		{
			if(fir+sec>cnt)
			break;
			if(fir==0&&sec!=0)
			{
				dp[u][sec]=max(dp[u][sec],w2+dp[v2][sec-1]);
			}
			else if(fir!=0&&sec==0)
			{
				dp[u][fir]=max(dp[u][fir],w1+dp[v1][fir-1]);
			}
			else if(fir!=0&&sec!=0)
			{
				dp[u][fir+sec]=max(dp[u][fir+sec],w1+dp[v1][fir-1]+w2+dp[v2][sec-1]);
			}
		}
	}
	return cnt;
}
signed main()
{
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,0);
	cout<<dp[1][q];
	return 0;
}
