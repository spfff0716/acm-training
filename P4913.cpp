#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int l[N],r[N],deep[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	deep[1]=1;
	int ans=1;
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(l[now]!=0)
		{
			q.push(l[now]);
			deep[l[now]]=deep[now]+1;
			ans=max(ans,deep[l[now]]);
		}
		if(r[now]!=0)
		{
			q.push(r[now]);
			deep[r[now]]=deep[now]+1;
			ans=max(ans,deep[r[now]]);
		}
	}
	cout<<ans;
	return 0;
}
