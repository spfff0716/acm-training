#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
double arr[N];
double pre[N];
int n,s,t;
bool check(double x)
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+arr[i]-x;
	}
	deque<int>q;
	for(int r=1;r<=n;r++)
	{
		int l1=r-s;
		if(l1>=0)
		{
			while(!q.empty()&&pre[l1]<=pre[q.front()])
			q.pop_back();
			q.push_back(l1);
		}
		int l2=r-t;
		while(!q.empty()&&q.front()<l2)
		{
			q.pop_front();
		}
		if(!q.empty())
		{
			int l=q.front();
			if(pre[r]-pre[l]>=0)
			return true;
		 } 
		
	}
	return false;
}
int main()
{
	cin>>n>>s>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	double r=N;
	double l=-N;
	for(int i=1;i<=50;i++)
	{
		double mid=(l+r)/2;
		if(check(mid))
		l=mid;
		else
		r=mid;
	}
	printf("%.3f",l);
	return 0;
}
