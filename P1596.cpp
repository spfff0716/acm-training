#include <bits/stdc++.h>
using namespace std;
const int N=105;
char arr[N][N];
bool vis[N][N];
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
int n,m;
void dfs(int x,int y)
{
	vis[x][y]=true;
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(arr[nx][ny]=='.')
		continue;
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny])
		dfs(nx,ny);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vis[i][j]||arr[i][j]=='.')
			continue;
			else
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
 } 
