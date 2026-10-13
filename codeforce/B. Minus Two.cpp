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
		int n;
		cin>>n;
		int max1=0;
		int max2=0;
		int max3=0;
		while(n--)
		{
			int x;
			cin>>x;
			if(x%2==0)
			{
				if((x/2)%2==0)
				max1++;
				else
				max2++;
			}
			else
			{
				max3++;
			}
		}
		int ans1=max(max1,max2);
		int ans=max(ans1,max3);
		cout<<ans<<endl;
	}
	return 0;
}
