#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e8+10;
long long arr[N];
int n;
long long k;
bool check(long long mid)
{
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i]/mid;
	}
	if(sum>=k)
	return true;
	return false;
}
int main()
{
	cin>>n>>k;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	if(sum<k)
	{
		cout<<0;
		return 0;
	}
	long long l=0;
	long long r=M;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if(check(mid))
		l=mid;
		else
		r=mid-1;
	}
	cout<<l;
	return 0;
}
