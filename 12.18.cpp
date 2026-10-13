#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	int cnt[1010]={0};
	cin>>n>>m;
	int num;
	for(int i=0;i<m;i++)
	{
		cin>>num;
		cnt[num]++;
	}
	for(int i=1;i<=n;i++)
	{
		
		while(cnt[i])
		{
			cout<<i<<" ";
			 cnt[i]--;
		}
	}
	return 0;
 } 
