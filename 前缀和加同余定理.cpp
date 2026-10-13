#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	 } 
	vector<long long>pre(n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+arr[i-1];
	}
	long long res=0;
	vector<int>cnt(k,0); 
	cnt[0]=1;
	for(int i=1;i<=n;i++)
	{
		int mod=pre[i]%k;
		res+=cnt[mod];
		cnt[mod]++;
	 } 
	cout<<res;
	return 0;
}
