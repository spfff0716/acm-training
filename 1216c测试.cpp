#include <bits/stdc++.h>
using namespace std;
const int N=550;
int arr[N][N];
int b[N][N];
int main()
{
		int n,m;
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<n;j++)
		{
			arr[i][j]=cnt;
			b[i][j]=cnt;
			cnt++;
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
