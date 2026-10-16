#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
int m,n,k,s,t;
const int N=3*1e4+10;
vector<pii>g[N];
struct node
{
    int x,y,z;

    bool operator < (const node& other) const
    {
        if(x != other.x) return x < other.x;
        if(y != other.y) return y < other.y;
        return z < other.z;
    }
};
map<pii,int>dist;
set<node>noturn;
const int INF=0x3f3f3f3f3f3f3f3f;
int res=INF;
void dj()
{
	dist[{-1,s}]=0;
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>q;
	q.push({0,{-1,s}});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int pre=now.second.first;
		int u=now.second.second;
		for(auto &it:g[u])
		{
			int v=it.first;
			int w=it.second;
			node turn = {pre,u,v};
			if(noturn.find(turn)!=noturn.end())
			continue;
			if(dist.find({u,v})!=dist.end())
			continue;
			else
			{
				dist[{u,v}]=dist[{pre,u}]+w;
				if(v==t)
				res=min(res,dist[{u,v}]);
				q.push({dist[{u,v}],{u,v}});
			}
		}
	}
}
signed main()
{
	cin>>m>>n>>k>>s>>t;
	while(m--)
	{
		int x,y,c;
		cin>>x>>y>>c;
		g[x].push_back({y,c});
	}
	while(k--)
	{
		int nx,ny,nz;
		cin>>nx>>ny>>nz;
		node now={nx,ny,nz};
		noturn.insert(now);
	}
	dj();
	if(res==INF)
	cout<<-1;
	else
	cout<<res;
	return 0;
}
