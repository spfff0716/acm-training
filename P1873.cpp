#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N=1e6+10;
const int M=4*1e5+10; 
int h[N];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	int l=0;
	int r=M;
	int res=0;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			if(h[i]>mid)
			ans+=h[i]-mid;
		}
		if(ans>=m)
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
