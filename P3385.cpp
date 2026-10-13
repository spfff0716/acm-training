#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e4;
vector<pii>g[N];
int dist[N];
int cnt[N];
bool fuhuan(int s,int n)
{
	memset(dist,0x3f,sizeof(dist));
	memset(cnt,0,sizeof(cnt));
	queue<int>q;
	dist[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(auto &p:g[now])
		{
			int u=p.first;
			int cost=p.second;
			if(dist[u]>dist[now]+cost)
			{
			q.push(u);
			cnt[u]++;
			if(cnt[u]>=n)
			return true;
			dist[u]=dist[now]+cost;
			}
		}
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	int n,m;
	while(t--)
	{
		cin>>n>>m;
		for(int j=1;j<=n;j++)
		{
			g[j].clear();
		}
		while(m--)
		{
			int u,v,w;
			cin>>u>>v>>w;
			if(w>=0)
			{
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			}
			else if(w<0)
			{
				g[u].push_back({v,w});
			}
		}
		if(fuhuan(1,n))
		{
			cout<<"YES";
		}
		else
		cout<<"NO";
		cout<<endl;
	}
	return 0;
}
