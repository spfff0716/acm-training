#include <bits/stdc++.h>
using namespace std;
const int N=5*1e4+10;
int l,n,m;
int arr[N];
bool check(int x)
{
	int last=0;
	int cnt=0;
	for(int i=1;i<=n+1;i++)
	{
		if(arr[i]-arr[last]<x)
		{
			cnt++;
		}
		else
		last=i;
	}
	return cnt<=m;
}
int main()
{
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	arr[0]=0;
	arr[n+1]=l;
	int left=0;
	int right=l;
	while(left<right)
	{
		int mid=(left+right+1)/2;
		if(check(mid))
		left=mid;
		else
		right=mid-1;
	}
	cout<<left;
	return 0;
}
