#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long arr[N],tree[4*N],lazy[4*N];
int n,m;
void build(int p,int l,int r)
{
	if(l==r)
	{
		tree[p]=arr[l];
		lazy[p]==0;
		return;
	}
	int mid=(l+r)/2;
	int lc=2*p;
	int rc=2*p+1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[p]=tree[lc]+tree[rc];
}
void pushdown(int p,int l,int r)
{
	if(lazy[p]==0)
	return;
	int mid=(r+l)/2;
	int lc=2*p;
	int rc=2*p+1;
	tree[lc]+=(mid-l+1)*lazy[p];
	lazy[lc]=lazy[p];
	tree[rc]+=(r-(mid+1)+1)*lazy[p];
	lazy[rc]=lazy[p];
	lazy[p]=0;
	
}
void add(int p,int l,int r,int left,int right,long long val)
{
	if(r<left||l>right)
	return;
	if(l>=left&&r<=right)
	{
		tree[p]+=val*(r-l+1);
		lazy[p]+=val;
		return;
	}
	pushdown(p,l,r);
	int mid=(l+r)/2;
	add(2*p,l,mid,left,right,val);
	add(2*p+1,mid+1,r,left,right,val);
	tree[p]=tree[2*p]+tree[2*p+1];
}
long long query(int p,int l,int r,int left,int right)
{
	if(r<left||l>right)
	return 0;
	if(l>=left&&r<=right)
	{
		return tree[p];
	}
	pushdown(p,l,r);
	int mid=(l+r)/2;
	int lc=2*p;
	int rc=2*p+1;
	long long L=query(lc,l,mid,left,right);
	long long R=query(rc,mid+1,r,left,right);
	return L+R;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	build(1,1,n);
	while(m--)
	{
		int num;
		cin>>num;
		if(num==1)
		{
			int x,y;
			long long k;
			cin>>x>>y>>k;
			add(1,1,n,x,y,k);
		}
		else
		{
			int x,y;
			cin>>x>>y;
			cout<<query(1,1,n,x,y)<<'\n';
		}
	}
	return 0;
 } 
