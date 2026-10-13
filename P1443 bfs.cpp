#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
bool vis[405][405];
int cnt[405][405];
struct node{
	int x,y,step;
};
void bfs(int sx,int sy)
{
	queue<node>q;
	memset(vis,0,sizeof(vis));
	q.push({sx,sy,0});
	vis[sx][sy]=true;
	cnt[sx][sy]=0;
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny])
			{
				vis[nx][ny]=true;
				cnt[nx][ny]=now.step+1;
				q.push({nx,ny,now.step+1});
			}
		}
	}
}
int main()
{
	int sx,sy;
	cin>>n>>m>>sx>>sy;
	bfs(sx,sy);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j])
			cout<<cnt[i][j]<<" ";
			else
			cout<<"-1 ";
		}
		cout<<endl;
	}
	return 0;
 } 
