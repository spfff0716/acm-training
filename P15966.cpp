#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(x<=y+1)
		{
			cout<<"1"<<endl;
			continue;
		}
		int n=x-(y+1);
		long long res=y+1;
		long long a=2;
		while(n>0)
		{
			if(n&1)
			{
				res=res*a%mod;
			}
			a=a*a%mod;
			n>>=1;
		}
		cout<<res<<endl;
	}
	return 0;
}
