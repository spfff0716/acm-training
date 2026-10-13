#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
ll arr[N];
ll n,m;
bool check(ll h)
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum+max(0ll,arr[i]-h);
	}
	if(sum>=m)
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
	ll r=4*1e5+10;
	while(l<r)
	{
		ll mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		r=mid-1;
	}
	cout<<l;
	return 0;
 } 
