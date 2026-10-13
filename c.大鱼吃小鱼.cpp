#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int M=0x3f3f3f3f;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
int res(vector<vector<int>> &arr,vector<vector<bool>> &vis,vector<pii> &record,int x,int y,int v)
{
	int sum=0;
	queue<pii>q;
	q.push({x,y});
	vis[x][y]=true;
	record.push_back({x,y});
	while(!q.empty())
	{
		auto it=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=it.first+dx[i];
			int ny=it.second+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&arr[nx][ny]!=M)
			{
				sum++;
				q.push({nx,ny});
				vis[nx][ny]=true;
				record.push_back({nx,ny});
			}
		}
	}
	return sum;
}
int add(vector<vector<int>> &arr,vector<vector<bool>> &vis,vector<pii> &record,int x,int y)
{
	int v=arr[x][y];
	int ans=0;
	queue<pii>q;
	q.push({x,y});
	vis[x][y]=true;
	record.push_back({x,y});
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>heap;
	while(!q.empty())
	{
		auto it=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=it.first+dx[i];
			int ny=it.second+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&arr[nx][ny]!=M)
			{
				if(v>=arr[nx][ny])
				{
					v++;
					q.push({nx,ny});
					vis[nx][ny]=true;
					record.push_back({nx,ny});
				}
				else
				{
					heap.push({arr[nx][ny],{nx,ny}});
				}
			}
		}
	}
	while(!heap.empty())
	{
		auto it=heap.top();
		int u=it.first;
		if(v<u)
		{
			ans+=(u-v);
			v=u;
		}
		heap.pop();	
		int nx=it.second.first;
		int ny=it.second.second;
		if(vis[nx][ny])
		continue;
		v++;
		q.push({nx,ny});
		vis[nx][ny]=true;
		record.push_back({nx,ny});
			while(!q.empty())
			{
				auto it=q.front();
				q.pop();
				for(int i=0;i<4;i++)
				{
					int nx=it.first+dx[i];
					int ny=it.second+dy[i];
					if(nx>0&&nx<=n&&ny>0&&ny<=m&&!vis[nx][ny]&&arr[nx][ny]!=M)
					{
						if(v>=arr[nx][ny])
						{
							v++;
							q.push({nx,ny});
							vis[nx][ny]=true;
							record.push_back({nx,ny});
						}
						else
						{
							heap.push({arr[nx][ny],{nx,ny}});
						}
					}
				}
			}
	}
	return ans;
}
int main()
{
	int q;
	cin>>n>>m>>q;
	vector<vector<int>> arr(n+1,vector<int>(m+1));
	vector<vector<bool>> vis(n+1,vector<bool>(m+1));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			arr[i][j]=M;
			vis[i][j]=false;
		}
	}
	int l=0;
	while(q--)
	{
		vector<pii>rec;
		int flag;
		cin>>flag;
		if(flag==1)
		{
			int x1,y1,v;
			cin>>x1>>y1>>v;
			int x=x1^l;
			int y=y1^l;
			arr[x][y]=v;
			l=res(arr,vis,rec,x,y,v);
			cout<<l<<endl;
		}
		else
		{
			int x1,y1;
			cin>>x1>>y1;
			int x=x1^l;
			int y=y1^l;
			l=add(arr,vis,rec,x,y);
			cout<<l<<endl;
		}
		for (auto &pos : rec)
			{
				int xx = pos.first;
				int yy = pos.second;
				vis[xx][yy] = false;
			}
		rec.clear();
	}
	return 0;
}
