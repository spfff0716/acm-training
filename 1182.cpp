#include <bits/stdc++.h>
using namespace std;
int n,m;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
int arr[N];
bool check(int x)
{
	int sum=0;
	int cnt=1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>x)
		return false;
		sum+=arr[i];
		if(sum>x)
		{
			sum=arr[i];
			cnt++;
		}
	}
	if(cnt<=m)
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
	int l=0;
	int r=INF;
	while(l<r)
	{
		int mid=l+(r-l)/2;
		if(check(mid))
		{
			r=mid;
		}
		else
		l=mid+1;
	}
	cout<<l;
	return 0;
}
