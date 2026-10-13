#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int n,m;
const int N=405;
int dist[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main()
{
	cin>>n>>m;
	int a,b;
	cin>>a>>b;
	memset(dist,-1,sizeof(dist));
	queue<pii>q;
	for(int i=0;i<a;i++)
	{
		int x,y;
		cin>>x>>y;
		dist[x][y]=0;
		q.push({x,y});
	}
	while(!q.empty())
	{
		auto it=q.front();
		q.pop();
		int x=it.first;
		int y=it.second;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<=0||nx>n||ny<=0||ny>m)
			{
				continue;
			 } 
			if(dist[nx][ny]==-1)
			{
				dist[nx][ny]=dist[x][y]+1;
				q.push({nx,ny});
			}
		}
	}
	for(int i=0;i<b;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]<<endl;
	}
	return 0;
}
