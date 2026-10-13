#include <bits/stdc++.h>
using namespace std;
const int N=1e8;
const int M=1e5+10;
int arr[M]; 
int main()
{
	int l,n,k;
	cin>>l>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int left=1;
	int right=N;
	while(left<right)
	{
		int cnt=0;
		int mid=(left+right)/2;
		for(int i=0;i<n-1;i++)
		{
			int dx=arr[i+1]-arr[i];
			if(dx<=mid)
			continue;
			else
			{
				cnt=cnt+dx/mid;
				if(dx%mid==0)
				cnt--;
			}
		}
		if(cnt<=k)
		right=mid;
		else
		left=mid+1;
	}
	cout<<left;
	return 0;
 } 
