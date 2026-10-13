#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,s,a,b;
	cin>>n>>s>>a>>b;
	int l=a+b;
	vector<int>use;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x<=l)
		{
			use.push_back(y);
			cnt++;
		}
	}
	sort(use.begin(),use.end());
	int res=0;
	for(int i=0;i<cnt;i++)
	{
		s=s-use[i];
		if(s<0)
		break;
		res++;
	}
	cout<<res;
	return 0;
}
