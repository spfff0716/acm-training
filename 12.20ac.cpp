#include <bits/stdc++.h>
using namespace std;
const int N=3*100000;
long a[N][2];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	long n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	int num;
	int i=0,l=0,r=0;
	long x,y;
	
	for(int j=0;j<q;j++)
	{
		cin>>num;
		if(num==1)
		{
			cin>>i>>x>>y;
			a[i][0]=x;
			a[i][1]=y;
		}
		else
		{
			cin>>l>>r>>x>>y;
			long max=0;
			for(int k=l;k<=r;k++)
			{
				long lg=abs(a[k][0]-x)+abs(a[k][1]-y);
				if(lg>max)
				max=lg;
			}
			cout<<max<<endl;
		}
	}
	return 0;
	
}
