#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		int ans=1;
		if(s[0]=='0')
		{
			cout<<-1<<'\n';
			continue;
		}
		int ok=1;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(i<n-1)
			{
				if(s[i]=='0'&&s[i+1]=='0')
				{
					ok=0;
					break;
				}
				if(s[i]!='0'&&s[i+1]!='0'&&s[i]!=s[i+1])
				{
					ans=2;
				}
			}
			if(s[i]!='0')
			cnt++;
			else
			{
				if(cnt%2==0)
				{
					ans=2;
				}
				else
				cnt=0;
			}
		}
		if(!ok)
		{
			cout<<-1<<'\n';
			continue;
		}
		if(ans==1)
		{
			cout<<ans<<'\n';
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(i<n-3)
			{
				if(s[i]==s[i+3]&&s[i+1]==s[i+2]&&s[i]!=s[i+1])
				{
					int flag=1;
					for(int j=i;j<=i+3;j++)
					{
						if(s[j]=='0')
						flag=0;
					}
					if(flag)
					{
						ans=3;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
 } 
