#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		ll s=a+b;
		ll x=0;
		ll cnt;
		for(int i=60;i>=1;i--)
		{
			if(s>>i&1ll)
			{
				cnt=x|(1ll<<i);
				if(cnt<=a)
				{
					x=cnt;
				}
			}
		}
		ll res=a-x;
		cout<<a+b<<" "<<res<<'\n';
	}
	return 0;
}



