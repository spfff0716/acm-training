#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int arr[N];
int fin(int x)
{
	int l=1;
	int r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(x>=arr[mid])
		l=mid;
		else
		r=mid-1;
	}
	if(arr[l]==x)
	return l;
	return -1;
}
int main()
{
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	while(m--)
	{
		int x;
		cin>>x;
		cout<<fin(x)<<" ";
	}
	return 0;
}
