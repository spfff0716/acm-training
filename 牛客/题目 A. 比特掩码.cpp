#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	ll cnt[31][4]={};
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=30;j++)
		{
			int high,low;
			if(j==30)
			high=0;
			else
			high=(x>>j)&1;
			low=(x>>(j-1))&1;
			int state=high*2+low;
			cnt[j][state]++;
		}
	}
	int change[31][2];
	for(int i=0;i<=30;i++)
	{
		change[i][0]=0;
		change[i][1]=1;
	}
	change[30][1]=0;
	int m;
	cin>>m;
	while(m--)
	{
		int type,x;
		cin>>type>>x;
		for(int i=0;i<30;i++)
		{
			int bit=(x>>i)&1;
			if(type==1)
			{
				if(bit==0)
				{
					change[i][0]=0;
					change[i][1]=0;
				}
			}
			else if(type==2)
			{
				if(bit==1)
				{
					change[i][0]=1;
					change[i][1]=1;
				}
			}
			else
			{
				if(bit==1)
				{
					change[i][0]=1-change[i][0];
					change[i][1]=1-change[i][1];
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=30;i++)
		{
			for(int s=0;s<4;s++)
			{
				int high=s/2;
				int low=s%2;
				high=change[i][high];
				low=change[i-1][low];
				if(high==0&&low==1)
				{
					ans+=cnt[i][s];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
