#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long l,r;
	cin>>l>>r;
	long long a,b;
	a=l;
	b=r;
	int flag=1;
	for(int i=60;i>=0;i--)
	{
		if(flag)
		{
			if(b&(1LL<<i))
			{
				flag=0;
				i++;
			}
		}
		else
		{
			if((b&(1LL<<i))!=(a&(1LL<<i)))
			continue;
			else if((b&(1LL<<i))&&(a&(1LL<<i)))
			{
				if(b-(1LL<<i)<l)
				continue;
				else
				b-=1LL<<i;
			}
			else
			{
				if(a+(1LL<<i)>r)
				continue;
				else
				a+=1LL<<i;
			}
		}
	}
	long long ans=a^b;
	cout<<ans;
	return 0;
 } 
