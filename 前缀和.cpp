#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
	cin>>a[i];
	int m;
	cin>>m;
	vector<int>sum(n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	cout<<sum[4]; 
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		int res=sum[r]-sum[l-1];
		cout<<res<<endl;
	}
	return 0;
}
