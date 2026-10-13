#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	const int m=3000;
	int flag=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<m;k++)
			{
				double x=sqrt(n-i*i-j*j-k*k);
				int l=int(x);
				if(fabs(x-l)<1e-9)
				{
					cout<<i<<" "<<j<<" "<<k<<" "<<l;
					flag=1;
					break;
				}
			}
			if(flag==1)
			break;
		}
		if(flag==1)
		break;
	}
	return 0;
}
