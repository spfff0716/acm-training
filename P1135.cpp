#include <bits/stdc++.h>
using namespace std;
bool vis[210];
int s[210];
int n;
struct node
{
	int num,step;
};
int bfs(int start,int end)
{
	queue<node>q;
	memset(vis,0,sizeof(vis));
	vis[start]=true;
	q.push({start,0});
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		if(now.num==end)
		return now.step;
		int newnum=now.num+s[now.num];
		if(newnum>=1&&newnum<=n&&!vis[newnum])
		{
			vis[newnum]=true;
			q.push({newnum,now.step+1});
		}
		newnum=now.num-s[now.num];
		if(newnum>=1&&newnum<=n&&!vis[newnum])
		{
			vis[newnum]=true;
			q.push({newnum,now.step+1});
		}
	}
	return -1;
	
}
int main()
{
	cin>>n;
	int start,end;
	cin>>start>>end;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	int ans=bfs(start,end);
	cout<<ans;
	return 0;
	
 } 
