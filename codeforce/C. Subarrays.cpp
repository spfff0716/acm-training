#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+10;
int arr[N];
int more[N];
int pre[N]; 
void solve()
{
	memset(arr,0,sizeof(arr));
	memset(pre,0,sizeof(pre));
	memset(more,0,sizeof(more));
	int n,k;
	cin>>n>>k;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		pre[i]=pre[i-1]+arr[i];
		pre[i]%=k;
	}
	for(int i=k+1;i<=n;i++)
	{
		more[pre[i-k-1]]++;
		res+=more[pre[i]];
	}
	cout<<res<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
 } 
