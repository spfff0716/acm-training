#include <bits/stdc++.h>
using namespace std;
int diff[1010][1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		diff[x1][y1]++;
		diff[x1][y2+1]--;
		diff[x2+1][y1]--;
		diff[x2+1][y2+1]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			diff[i][j]=diff[i][j]+diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
			cout<<diff[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
