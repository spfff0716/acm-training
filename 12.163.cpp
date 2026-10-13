#include <bits/stdc++.h>
using namespace std;
const int N=550;
int arr[N][N];
int b[N][N];
void zhuanzhi(int a[][N],int b[][N],int x,int y,int r,int z)
{
	
	if(z==1)
	{
	for(int i=-r;i<=r;i++)
	{
		for(int j=-r;j<=r;j++)
		{
			a[x-j][y+i]=b[x+i][y+j];
		}}
		for(int i=-r;i<=r;i++)
	{
		for(int j=-r;j<=r;j++)
		{
			b[x+i][y+j]=a[x+i][y+j];
		}}
		
	}
	else
	{
		for(int i=-r;i<=r;i++)
	{
		for(int j=-r;j<=r;j++)
		{
			a[x+j][y-i]=b[x+i][y+j];
		}
		
	}
	for(int i=-r;i<=r;i++)
	{
		for(int j=-r;j<=r;j++)
		{
			b[x+i][y+j]=a[x+i][y+j];
		}
	}
	
}}

int main()
{
	
	int n,m;
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=n;j++)
		{
			arr[i][j]=cnt;
			b[i][j]=cnt;
			cnt++;
		}
	}
	int x,y,r,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>r>>z;
		zhuanzhi(arr,b,x,y,r,z);
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
