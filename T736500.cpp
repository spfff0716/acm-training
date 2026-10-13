#include <bits/stdc++.h>
using namespace std;
const int N=5*1e3+10;
const long long INF=0x3f3f3f3f3f3f3f3f;
int n,m;
long long arr[N],dist[N],sum1[N],sum2[N];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum1[i+1]=sum1[i]+arr[i];
	}
	while(m--)
	{
		long long k;
		cin>>k;
		for(int i=0;i<n;i++)
		{
			long long x=arr[i]^k;
			sum2[i+1]=sum2[i]+x;
			dist[i+1]=sum2[i+1]-sum1[i+1];
		}
		long long m1=INF;
		long long m2=-INF;
		long long premin=dist[0];
		long long premax=dist[0];
		for(int i=2;i<=n;i++)
	{
		m1=min(m1,dist[i]-premax);
		m2=max(m2,dist[i]-premin);
		premin=min(premin,dist[i-1]);
		premax=max(premax,dist[i-1]);
	}
	m1+=sum1[n];
	m2+=sum1[n];
	cout<<m1<<" "<<m2<<endl;
		
	}
	return 0;
}
