#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=120;
const int M=1500;
const int INF=0x3f3f3f3f; 
int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int tong[N][N];
int have[N];
int dist[N][M];
bool vis[N][M];
int dj(int s1,int s2)
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	int start=(s1-1)*m+s2;
	int s3=have[start];
	dist[start][s3]=0;
	priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>>q;
	q.push({{0,start},s3});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int w=now.first.second;
		int cnt=now.second;
		int x=(w-1)/m+1;
		int y=(w-1)%m+1;
		if(vis[w][cnt])
		continue;
		vis[w][cnt]=true;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m)
			continue;
			int nw=(nx-1)*m+ny;
			int ncnt=cnt|have[nw];
			if(tong[w][nw]==0||vis[nw][ncnt])
			continue;
			if(tong[w][nw]>0)
			{
				if(!(cnt&(1<<tong[w][nw])))
				continue;
			}
			if(dist[nw][ncnt]>dist[w][cnt]+1)
			{
				dist[nw][ncnt]=dist[w][cnt]+1;
				q.push({{dist[nw][ncnt],nw},ncnt});
			}
		}
	}
}
int main()
{
	int p,k;
	cin>>n>>m>>p>>k;
	memset(tong,-1,sizeof(tong));
	while(k--)
	{
		int x1,y1,x2,y2,g;
		cin>>x1>>y1>>x2>>y2>>g;
		tong[(x1-1)*m+y1][(x2-1)*m+y2]=g;
		tong[(x2-1)*m+y2][(x1-1)*m+y1]=g;
	}
	int s;
	cin>>s;
	while(s--)
	{
		int x1,y1,q;
		cin>>x1>>y1>>q;
		have[(x1-1)*m+y1]=have[(x1-1)*m+y1]|(1<<q);
	}
	dj(1,1);
	int ans=INF;
	for(int i=0;i<=M;i++)
	{
		if(vis[(n-1)*m+m][i])
		ans=min(ans,dist[(n-1)*m+m][i]);
	}
	if(ans==INF)
	cout<<-1;
	else
	cout<<ans;
	return 0;
}
