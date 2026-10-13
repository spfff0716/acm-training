#include <bits/stdc++.h>
using namespace std;
long long res=0;
void dfs(int sum1,int sum2)
{
	if(sum1==0&&sum2==0)
	{
		res++;
		return;
	}
	if(sum1>0)
	{
		if(sum2==0)
		{
			res++;
			return;
		}
		dfs(sum1-1,sum2);
	}
	if(sum2>0)
	{
		dfs(sum1+1,sum2-1);
	}
}
int main()
{
	int n;
	cin>>n;
	dfs(0,n);
	cout<<res;
	return 0;
 } 
