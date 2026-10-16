#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c,d;
};
const int N=360;
vector<int> sum[N];
int core[N];
int n,m;
void solve(int u,int nowsum,node now)
{
	int a1=now.a;
	int b1=now.b;
	int c1=now.c;
	int d1=now.d;
	if(a1>0)
	{
		sum[u+1].push_back(nowsum+core[u+1]);
		solve(u+1,nowsum+core[u+1],{a1-1,b1,c1,d1});
	}
	if(b1>0)
	{
		sum[u+2].push_back(nowsum+core[u+2]);
		solve(u+2,nowsum+core[u+2],{a1,b1-1,c1,d1});
	}
	if(c1>0)
	{
		sum[u+3].push_back(nowsum+core[u+3]);
		solve(u+3,nowsum+core[u+3],{a1,b1,c1-1,d1});
	}
	if(d1>0)
	{
		sum[u+4].push_back(nowsum+core[u+4]);
		solve(u+4,nowsum+core[u+4],{a1,b1,c1,d1-1});
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>core[i];
	}
	node card={0,0,0,0};
	while(m--)
	{
		int x;
		cin>>x;
		if(x==1)
		card.a++;
		else if(x==2)
		card.b++;
		else if(x==3)
		card.c++;
		else
		card.d++;
	}
	solve(1,core[1],card);
	int res=0;
	for(auto score:sum[n])
	{
		res=max(res,score);
	}
	cout<<res;
	return 0;
}
