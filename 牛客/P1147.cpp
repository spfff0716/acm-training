#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	int l=1;
	int sum=1;
	for(int r=2;r<=m/2+1;r++)
	{
		sum+=r;
		while(sum>m)
		{
			sum-=l;
			l++;
		}
		if(sum==m)
		{
			cout<<l<<" "<<r<<endl;
		}
	}
	return 0;
}
