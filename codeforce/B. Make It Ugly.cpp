#include <bits/stdc++.h>
using namespace std;
const int N=300010;
int arr[N];
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
		int x;
		cin>>x;
		int idex=0;
		int ans=N;
		int y;
		for(int i=2;i<=n;i++)
		{
			cin>>y;
			if(y!=x)
			{
				ans=min(ans,i-idex-1);
				idex=i;
			}
		}
		if(idex!=0)
		{
			ans=min(ans,n-idex);
		}
		if(idex==0)
		{
			cout<<-1<<'\n';
		}
		else
		{
			cout<<ans<<'\n';
		}
	}
	return 0;
 } 
