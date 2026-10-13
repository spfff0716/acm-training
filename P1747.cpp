#include <bits/stdc++.h>
using namespace std;
bool vis[100][100];
struct node
{
	int u,v,cnt;
};
int dx[]={1,1,-1,-1,2,2,-2,-2,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1,2,-2,2,-2};
int bfs(int x,int y)
{
	queue<node>q;
	q.push({x,y,0});
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		if (now.u == 1 && now.v == 1)
		return now.cnt;
		for(int i=0;i<12;i++)
		{
			int nx=now.u+dx[i];
			int ny=now.v+dy[i];
			int nc=now.cnt+1;
			if(nx<=0||ny<=0||vis[nx][ny])
			continue;
			q.push({nx,ny,nc});
			vis[nx][ny]=true;
		}
	}
	return 0;
	
}
int main()
{
	int x,y;
	cin>>x>>y;
	cout<<bfs(x,y)<<endl;
	memset(vis,false,sizeof(vis));
	cin>>x>>y;
	cout<<bfs(x,y)<<endl;
	return 0;
 } 
