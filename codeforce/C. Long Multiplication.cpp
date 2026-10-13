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
		string a,b;
		cin>>a>>b;
		int n=a.size();
		int idex=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				idex=i;
				break;
			}
		}
		if(a[idex]>b[idex])
		{
			for(int i=idex+1;i<n;i++)
			{
				if(a[i]>b[i])
				{
					char c=a[i];
					a[i]=b[i];
					b[i]=c;
				}
			}
		}
		else
		{
			for(int i=idex+1;i<n;i++)
			{
				if(b[i]>a[i])
				{
					char c=a[i];
					a[i]=b[i];
					b[i]=c;
				}
			}
		}
		cout<<a<<endl<<b<<endl;
	}
	return 0;
}
