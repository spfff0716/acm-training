#include <bits/stdc++.h>
using namespace std;
const int N=1e9;
const int M=1e5+10;
int n,m;
int arr[M];
bool check(long x)
{
	int cnt=1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>x)
		return false;
		if(sum+arr[i]<=x)
		{
			sum+=arr[i];
		}
		else
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
	long left=1;
	long right=N;
	while(left<right)
	{
		long mid=(left+right)/2;
		if(check(mid))
		{
			right=mid;
		}
		else
		left=mid+1;
		
	}
	cout<<left;
	return 0;
 } 
