#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N];
int n,m;
bool check(long x)
{
	int now=0;
	int cnt=1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]-arr[now]>=x)
		{
			now=i;
			cnt++;
		}
	}
	if(cnt>=m)
	return true;
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	long l=0;
	long r=1e9;
	while(l<r)
	{
		long mid=(l+r+1)/2;
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
