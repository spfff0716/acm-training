#include <bits/stdc++.h>
using namespace std;
int main()
{
	int w,n;
	cin>>w>>n;
	vector<int>price(n);
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	sort(price.begin(),price.end());
	int bigid=n-1;
	int sid=0;
	int res=n;
	while(bigid>sid)
	{
		if(price[bigid]+price[sid]>w)
		{
			bigid--;
		}
		else
		{
			bigid--;
			sid++;
			res--;
		}
	}
	cout<<res;
	return 0;
}
