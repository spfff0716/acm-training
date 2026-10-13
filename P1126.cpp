#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int n,m;
const int N=55;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int arr[N][N];
int dist[N][N][4];
void bfs(int stx,int sty,int face)
{
	dist[stx][sty][face]=0;
	queue<pair<pii,int>>q;
	q.push({{stx,sty},face});
	while(!q.empty())
	{
		auto it=q.front();
		q.pop();
		int x=it.first.first;
		int y=it.first.second;
		int fc=it.second;
		for(int i=1;i<=3;i++)
		{
			int nx=x+dx[fc]*i;
			int ny=y+dy[fc]*i;
			if(nx<0||nx>n||ny<0||ny>m)
			break;
			if(arr[nx][ny]||dist[nx][ny][fc]!=-1)
			break;
			dist[nx][ny][fc]=dist[x][y][fc]+1;
			q.push({{nx,ny},fc});
		}
		int leftface = (fc + 3) % 4;
		int rightface = (fc + 1) % 4;
		if(dist[x][y][leftface]==-1)
		{
			dist[x][y][leftface]=dist[x][y][fc]+1;
			q.push({{x,y},leftface});
		}
		if(dist[x][y][rightface]==-1)
		{
			dist[x][y][rightface]=dist[x][y][fc]+1;
			q.push({{x,y},rightface});
		}
	}
}
int main()
{
	memset(dist,-1,sizeof(dist));
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			if(x==1)
			{
				arr[i][j]=1;
				arr[i+1][j]=1;
				arr[i][j+1]=1;
				arr[i+1][j+1]=1;
			}
		}
	}
	int stx,sty,edx,edy;
	char c;
	cin>>stx>>sty>>edx>>edy>>c;
	string s="ESWN";
	int face;
	for(int i=0;i<4;i++)
	{
		if(c==s[i])
		{
			face=i;
			break;
		}
	}
	bfs(stx,sty,face);
	int flag=0;
	int ans=0;
	for(int i=0;i<4;i++)
	{
		if(flag==0)
		{
			if(dist[edx][edy][i]!=-1)
			{
				flag=1;
				ans=dist[edx][edy][i];
			}
		}
		else
		{
			if(dist[edx][edy][i]!=-1)
			ans=min(dist[edx][edy][i],ans);
		}
	}
	cout<<ans;
	return 0;
 } 
