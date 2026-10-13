#include <bits/stdc++.h>
using namespace std;
int m,n;
const int N=1e5+10;
int sch[N];
long long check(int x)
{
	int l=0;
	int r=m;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(sch[mid]>=x)
		r=mid;
		else
		l=mid+1;
	}
	if(l>0)
	return min(abs(sch[l]-x),abs(sch[l-1]-x));
	return abs(sch[l]-x);
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>sch[i];
	}
	sort(sch,sch+m);
	int x;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		
		cin>>x;
		ans+=check(x);
	}
	cout<<ans;
	return 0;
	
	
 } 
