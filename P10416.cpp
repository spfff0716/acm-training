#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int t;
	cin>>t;
	while(t--)
	{
		long long l,r,sum;
		cin>>l>>r;
		long long n=r-2*l+1;
		if(n<=0)
		cout<<0;
		else
		{
			sum=(n+1)*n/2;
			cout<<sum;
		 }
		cout<<'\n';
	}
	return 0;
 } 
