#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long arr[N];
int n,m;
struct node
{
	int l,r;
	long long sum;
}tree[4*N];
void pushup(int p)
{
	int lc=2*p;
	int rc=2*p+1;
	tree[p].sum=tree[lc].sum+tree[rc].sum;
}
void build(int p,int left,int right)
{
	tree[p].l=left;
	tree[p].r=right;
	tree[p].sum=0;
	if(left==right)
	{
		tree[p].sum=arr[left];
		return;
	}
	int mid=(left+right)/2;
	int lc=2*p;
	int rc=2*p+1;
	build(lc,left,mid);
	build(rc,mid+1,right);
	pushup(p);
}
void update(int p,int idex,long long val)
{
	int left=tree[p].l;
	int right=tree[p].r;
	if(left==right)
	{
		tree[p].sum+=val;
		return;
	}
	int mid=(left+right)/2;
	if(idex<=mid)
	{
		update(2*p,idex,val);
	}
	else
	{
		update(2*p+1,idex,val);
	}
	pushup(p);
}
long long qurry(int p,int la,int ra)
{
	int left=tree[p].l;
	int right=tree[p].r;
	if(la>right||ra<left)
	return 0;
	if(la<=left&&ra>=right)
	{
		return tree[p].sum;
	}
	return qurry(2*p,la,ra)+qurry(2*p+1,la,ra);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		long long num,a,b;
		cin>>num>>a>>b;
		if(num==1)
		{
			update(1,a,b);
		}
		else
		{
			cout<<qurry(1,a,b)<<endl;
		}
	}
	return 0;
 } 
