#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int dp[1010];
vector<pii> back[110];
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		int w,v,num;
		cin>>w>>v>>num;
		back[num].push_back({w,v});
	}
for(int j=m;j>=0;j--)
{
    for(int i=1;i<=105;i++)
    {
        if(back[i].empty())continue;
        for(auto &now:back[i])
        {
            int w=now.first,v=now.second;
            if(j>=w) dp[j]=max(dp[j],dp[j-w]+v);
        }
    }
}
	cout<<dp[m];
	return 0;
}
