#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int arr[35][35];
bool vis[35][35];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n;
vector<pii>p;
bool bfs(int x,int y)
{
	bool flag=true;
	p.push_back({x,y});
	queue<pii>q;
	q.push({x,y});
	while(!q.empty())
	{
		auto now=q.front();
		q.pop();
		int px=now.first;
		int py=now.second;
		if(vis[px][py])
		continue;
		vis[px][py]=true;
		for(int i=0;i<4;i++)
		{
			int nx=now.first+dx[i];
			int ny=now.second+dy[i];
			if(nx<1||nx>n||ny<1||ny>n)
			{
				continue;
			 } 
			if(vis[nx][ny]||arr[nx][ny]==1)
			{
				continue;
			}
			if(nx==1||nx==n||ny==1||ny==n)
			{
				flag=false;
			 } 
			p.push_back({nx,ny});
			q.push({nx,ny});
		}
	}
	return flag;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<n;j++)
		{
			if(vis[i][j]||arr[i][j]==1)
			continue;
			p.clear();
			if(bfs(i,j))
			{
				for(auto &it:p)
				{
					int nx=it.first;
					int ny=it.second;
					arr[nx][ny]=2;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
 } 
