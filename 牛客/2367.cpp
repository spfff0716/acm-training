#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,p;
	cin>>n>>p;
	vector<int>arr(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	vector<int>diff(n+2,0);
	while(p--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		diff[x]+=z;
		diff[y+1]-=z;
	}
	int ans=105;
	for(int i=1;i<=n;i++)
	{
		diff[i]+=diff[i-1];
		arr[i]+=diff[i];
		ans=min(ans,arr[i]);
	}
	cout<<ans;
	return 0;
 } 
