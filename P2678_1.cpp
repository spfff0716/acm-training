#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,n,m;
const int N=5*1e4+10;
int arr[N];
bool check(int x)
{
	if(x>l)
	return false;
	int cnt=0;
	int idex=0;
	for(int i=1;i<=n+1;i++)
	{
		if(arr[i]-arr[idex]<x)
		{
			cnt++;
		}
		else
		idex=i;
	}
	if(cnt<=m)
	return true;
	return false;
}
signed main()
{
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	arr[0]=0;
	arr[n+1]=l;
	int le=0;
	int r=1e9;
	while(le<r)
	{
		int mid=(le+r+1)/2;
		if(check(mid))
		le=mid;
		else
		r=mid-1;
	}
	cout<<le;
	return 0;
 } 
