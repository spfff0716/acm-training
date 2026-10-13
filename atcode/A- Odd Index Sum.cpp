#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3*1e5+10;
int l[N],r[N];
int le[N],ri[N]; 
signed main()
{
	int n,q;
	cin>>n>>q;
	memset(le,0x3f,sizeof(le));
	memset(ri,0x3f,sizeof(ri));
	for(int i=2;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>r[i];
		ri[i]=min(ri[i-1],r[i]);
	}
	for(int i=n;i>=2;i--)
	{
		le[i]=min(le[i+1],l[i]);
	}
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		int res;
		if(s<t)
		{
			res=r[s];
			if(s!=1)
			res=min(res,l[s]+ri[s]);
		}
		else
		{
			res=l[s];
			if(s!=n)
			res=min(res,r[s]+le[s]);
		}
		cout<<res<<'\n';
	}
	return 0;
}
