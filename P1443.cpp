#include<bits/stdc++.h>
using namespace std;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
struct node
{
	int x;
	int y;
	int step;
};
int n,m;
bool vis[405][405];
int cnt[405][405];
void bfs(int sx,int sy)
{
	queue<node>q;
	q.push({sx,sy,0});
	cnt[sx][sy]=0;
	vis[sx][sy]=true;
	while(!q.empty())
	{
		node arr=q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			int nx=arr.x+dx[i];
			int ny=arr.y+dy[i];
			if(nx<=0||nx>n||ny<=0||ny>m)
			continue;
			if(vis[nx][ny])
			continue;
			vis[nx][ny]=true;
			cnt[nx][ny]=arr.step+1;
			q.push({nx,ny,arr.step+1});
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
			{
				cout<<cnt[i][j]<<" ";
			}
			else
			cout<<-1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
