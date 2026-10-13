#include <bits/stdc++.h>
using namespace std;
struct line
{
	long long base[31];
	
	line()
	{
		memset(base,0,sizeof(base));
	}
	void insert(long long x)
	{
		for(int i=30;i>=0;i--)
		{
			if(((x>>i)&1)==0)
			continue;
			else
			{
				if(base[i]==0)
				{
					base[i]=x;
					return;
				}
				else
				{
					x^=base[i];
				}
			}
		}
	}
	long long getmax(long long sum)
    {
        long long ans=0;
        long long mask=(1LL<<31)-1;
        mask^=sum;
        for(int i=30;i>=0;i--)
        {
            if(base[i]==0)
            continue;
            long long now=ans^base[i];
            if((now&mask)>(ans&mask))
            {
                ans=now;
            }
        }
        return ans&mask;
    }
	 
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		line arr;
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			long long x;
			cin>>x;
			sum^=x;
			arr.insert(x);
		}
		long long res=arr.getmax(sum);
		cout<<res+(sum^res)<<endl;
	}
	return 0;
}
