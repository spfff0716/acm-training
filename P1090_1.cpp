#include <bits/stdc++.h>
using namespace std;
int arr[10][10];
bool vis[10][10];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m,t;
int sx,sy,fx,fy;
int ans=0;
void dfs(int x,int y)
{
	if(x==fx&&y==fy)
	{
		ans++;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m)
		continue;
		if(arr[nx][ny]||vis[nx][ny])
		continue;
		vis[nx][ny]=true;
		dfs(nx,ny);
		vis[nx][ny]=false;
	}
}
int main()
{
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		arr[x][y]=1;
	}
	vis[sx][sy]=true;
	dfs(sx,sy);
	cout<<ans;
	return 0;
}
