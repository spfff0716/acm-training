#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>h(n);
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	sort(h.begin(),h.end());
	int highid=n-1;
	int lowid=0;
	long long res=0;
	res+=h[highid]*h[highid];
	int flag=0;
	while(highid>lowid)
	{
		res+=(h[highid]-h[lowid])*(h[highid]-h[lowid]);
		if(flag==0)
		{
			highid--;
			flag=1;
		}
		else
		{
			lowid++;
			flag=0;
		}
	}
	cout<<res;
	return 0;
 } 
