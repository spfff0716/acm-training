#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5*1e5+10;
const int INF=0x3f3f3f3f;
int dist[N][2];
vector<int>g[N];
void bfs(int n)
{
	for(int i=1;i<=n;i++)
	{
		dist[i][0]=INF;
		dist[i][1]=INF;
	}
	dist[1][0]=0;
	queue<pair<int,int>>q;
	q.push({1,0});
	while(!q.empty())
	{
		int u=q.front().first;
		int num=q.front().second;
		q.pop();
		for(auto &v:g[u])
		{
			int nextnum=num^1;
			if(dist[v][nextnum]==INF)
			{
				dist[v][nextnum]=dist[u][num]+1;
				q.push({v,nextnum});
			}
		}
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
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bfs(n);
		vector<int>ans(n+1,INF);
		ans[1]=0;
		if(k%2==0)
		{
			for(int i=2;i<=n;i++)
			{
				if(dist[i][0]==INF)
				{
					ans[i]=-1;
				}
				else
				{
					int w=dist[i][0];
					if(w%k==0)
					{
						ans[i]=w;
					}
					else
					{
						ans[i]=(w/k+1)*k;
					}
				}
			}
		}
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(dist[i][0]==INF&&dist[i][1]==INF)
				{
					ans[i]=-1;
				}
				if(dist[i][0]!=INF)
				{
					int w=dist[i][0];
					if(w%k==0)
					{
						ans[i]=w;
					}
					else
					{
						if((w/k)%2==1)
						ans[i]=min(ans[i],(w/k+1)*k);
						else
						ans[i]=min(ans[i],(w/k+2)*k);
					}
				}
				if(dist[i][1]!=INF)
				{
					int w=dist[i][1];
					if(w%k==0)
					{
						ans[i]=min(ans[i],w);
					}
					else
					{
						if((w/k)%2==0)
						ans[i]=min(ans[i],(w/k+1)*k);
						else
						ans[i]=min(ans[i],(w/k+2)*k);
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
