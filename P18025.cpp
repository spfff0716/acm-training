#include <bits/stdc++.h>
using namespace std;
struct node
{
	int lose;
	int win;
	int use;
};
int main()
{
	int n,x;
	long long sum=0;
	cin>>n>>x;
	vector<int>dp(x+1,0);
	vector<vector<int>>arr(x+1);
	vector<node>mess(n);
	for(int i=0;i<n;i++)
	{
		int w;
		cin>>mess[i].lose>>w>>mess[i].use;
		mess[i].win=w-mess[i].lose;
		sum+=mess[i].lose;
		
	}
	for(int i=0;i<n;i++)
	{
		int used=mess[i].use;
		for(int j=x;j>=used;j--)
		{
			dp[j]=max(dp[j],dp[j-used]+mess[i].win);
		}
	}
	sum+=dp[x];
	cout<<5*sum;
	return 0;
	
}
