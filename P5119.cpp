#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
int n,m,c;
int arr[N];
bool check(int x)
{
	int cnt=1;
	int sum=1;
	int now=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]-now>x||sum==c)
		{
			now=arr[i];
			cnt++;
			sum=1;
		}
		else
		{
			sum++;
		}
	}
	return cnt<=m;
}
int main()
{
	cin>>n>>m>>c;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
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
