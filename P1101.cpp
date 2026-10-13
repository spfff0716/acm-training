#include <bits/stdc++.h>
using namespace std;
char arr[110][110];
char brr[110][110];
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
bool vis[110][110];
char need[]="yizhong";
int n;
void dfs(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int nx=x;
		int ny=y;
		int flag=1;
		for(int j=1;j<7;j++)
		{
			nx=nx+dx[i];
			ny=ny+dy[i];
			if(nx<0||nx>=n||ny<0||ny>=n)
			{
				flag=0;
				break;
			}
			if(arr[nx][ny]!=need[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			int nx=x;
			int ny=y;
			brr[nx][ny]=arr[nx][ny];
			vis[nx][ny]=true;
			for(int j=1;j<7;j++)
			{
				nx=nx+dx[i];
				ny=ny+dy[i];
				brr[nx][ny]=arr[nx][ny];
				vis[nx][ny]=true;
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]=='y')
			dfs(i,j);
			if(vis[i][j])
			continue;
			brr[i][j]='*';
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<brr[i][j];
		}
		cout<<'\n';
	}
	return 0;
 } 
