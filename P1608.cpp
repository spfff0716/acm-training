#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int>pii;
const int N=2005;
int dist[N];
bool vis[N];
long long cnt[N];
int arr[N][N];
vector<pii>g[N];
void dj(int st)
{
	memset(dist,0x3f,sizeof(dist));
	dist[st]=0;
	cnt[st]=1;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,st});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int w=now.first;
		int u=now.second;
		if(vis[u])
		continue;
		vis[u]=true;
		for(auto &it:g[u])
		{
			int v=it.first;
			int c=it.second;
			if(dist[v]==w+c)
			{
				cnt[v]=cnt[u]+cnt[v];
			}
			else if(dist[v]>w+c)
			{
				dist[v]=w+c;
				cnt[v]=cnt[u];
				q.push({dist[v],v});
			}
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	memset(arr,0x3f,sizeof(arr));
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(arr[u][v]>w)
		{
			arr[u][v]=w;
			g[u].push_back({v,w});
		}
	}
	dj(1);
	if(dist[n]==INF)
	cout<<"No answer";
	else
	{
		cout<<dist[n]<<" "<<cnt[n];
	}
	return 0;
 } 
