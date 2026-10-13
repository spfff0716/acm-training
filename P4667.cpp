#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
int n,m;
const int N=550;
int dx[]={-1,1,1,-1};
int dy[]={-1,1,-1,1};
int dx1[]={0,1,1,0};
int dy1[]={0,1,0,1};
bool arr[N][N];
bool vis[N][N];
int cost[N][N];
void dj()
{
	memset(cost,0x3f,sizeof(cost));
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>q;
	q.push({0,{0,0}});
	cost[0][0]=0;
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int x=now.second.first;
		int y=now.second.second;
		if(vis[x][y])
		continue;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>n||ny<0||ny>m||vis[nx][ny])
			continue;
			int bx=x+dx1[i];
			int by=y+dy1[i];
			if((arr[bx][by]&&i<=1)||(!arr[bx][by]&&i>=2))
			{
				if(cost[nx][ny]>cost[x][y])
				{
					cost[nx][ny]=cost[x][y];
					q.push({cost[nx][ny],{nx,ny}});
				}
			}
			else
			{
				if(cost[nx][ny]>cost[x][y]+1)
				{
					cost[nx][ny]=cost[x][y]+1;
					q.push({cost[nx][ny],{nx,ny}});
				}
			}
		}
	}
}
signed main()
{
	cin>>n>>m;
	char x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			if(x!='/')
			arr[i][j]=true;
			else
			arr[i][j]=false;
		}
	}
	if(n%2!=m%2)
	{
		cout<<"NO SOLUTION";
		return 0;
	}
	dj();
	cout<<cost[n][m];
	return 0;
}
