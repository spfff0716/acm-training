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
		int n,k;
		int ans=0;
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i=0;i<n/k;i++)
		{
			bool flag=true;
			for(int j=0;j<k;j++)
			{
				if(s[i*k+j]=='0')
				{
					flag=false;
					break;
				}
			}
			if(flag)
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
