#include <bits/stdc++.h>
using namespace std;
int res=0;
int dx[]={1,1,-1,-1};
int dy[]={1,-1,1,-1};
bool vis[10][10];
int fx,fy,n,m;
void dfs(int x,int y)
{
	if(x==fx&&y==fy)
	{
		res++;
		return;
	}
	int nx,ny;
	for(int i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<=0||nx>n||ny<=0||ny>m)
		continue;
		if(vis[nx][ny])
		continue;
		vis[nx][ny]=true;
		dfs(nx,ny);
		vis[nx][ny]=false;
	}
	
}
int main()
{
	int t;
	cin>>n>>m>>t;
	int sx,sy;
	cin>>sx>>sy>>fx>>fy;
	vis[sx][sy]=true;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		vis[a][b]=true;
	}
	dfs(sx,sy);
	cout<<res;
	return 0;
}
