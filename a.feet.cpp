#include <bits/stdc++.h>
using namespace std;
const int N=3000010;
long long a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int j=0;j<m;j++)
	cin>>b[j];
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum=sum+abs(a[i]-b[j]);
			sum%=998244353;
		}
	}
	cout<<sum;
	return 0;
}
