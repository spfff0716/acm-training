#include<bits/stdc++.h>
using namespace std;
const int N=5*1e6+10;
int score[N],b[N];
int main()
{
	int n,p;
	cin>>n>>p;
	int res=100;
	for(int i=1;i<=n;i++)
	{
		cin>>score[i];
	}
	b[1]=score[1];
	for(int i=2;i<=n;i++)
	{
		b[i]=score[i]-score[i-1];
	}
	while(p--)
	{
		int l,r,z;
		cin>>l>>r>>z;
		b[l]+=z;
		b[r+1]-=z;
		
	}
	for(int i=1;i<=n;i++)
	{
		b[i]+=b[i-1];
		res=min(res,b[i]);
	}
	cout<<res;
	return 0;
}
