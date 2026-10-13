#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int cnt[N];
vector<int>g[N];
bool vis1[N];
bool vis2[N];
void bfs(queue<int> &q)
{
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto &v:g[u])
		{
			cnt[v]++;
			if(cnt[v]>=2)
			{
				if(vis2[v])
				continue;
				else
				{
					vis2[v]=true;
					q.push(v);
				}
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
			cnt[i]=0;
			vis1[i]=false;
			vis2[i]=false;
		}
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
		queue<int>q;
		for(int i=1;i<=k;i++)
		{
			int a;
			cin>>a;
			q.push(a);
			vis1[a]=true;
			vis2[a]=true;
		}
		bfs(q);
		vector<int>ans;
		for(int i=1;i<=n;i++)
		{
			if(!vis1[i])
			{
				if(cnt[i]>=1)
				{
					ans.push_back(i);
				}
			}
		}
		cout<<ans.size();
		cout<<'\n';
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<'\n';
	}
	return 0;
 } 
