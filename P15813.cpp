#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long arr[2*N],pre[2*N];
int n;
bool check(long long x)
{
	for(int i=1;i<=n;i++)
	{
		int j=lower_bound(pre+i,pre+i+n+1,pre[i-1]+x)-pre;
		if(j>i+n)
		continue;
		int k=lower_bound(pre+j+1,pre+i+n+1,pre[j]+x)-pre;
		if(k>i+n)
		continue;
		if((pre[n]-(pre[k]-pre[i-1]))>=x)
		return true;
	}
	return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		arr[i+n]=arr[i];
	}
	for(int i=1;i<=2*n;i++)
	{
		pre[i]=pre[i-1]+arr[i];
	}
	long long l=0;
	long long r=pre[n]/3+1;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
