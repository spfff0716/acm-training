#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
ll arr[N];
ll n,m;
bool check(ll x)
{
	ll cnt=1;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]>x)
		return false;
		if(sum+arr[i]>x)
		{
			cnt++;
			sum=arr[i];
		}
		else
		{
			sum+=arr[i];
		}
	}
	if(cnt<=m)
	return true;
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	ll l=0;
	ll r=1e9;
	while(l<r)
	{
		ll mid=(l+r)/2;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	cout<<l;
	return 0;
 } 
