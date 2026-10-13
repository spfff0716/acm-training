#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5;
const int INF=0x3f3f3f3f;
int tree[4*N],tree1[4*N];
int arr[N];
void build(int p,int l,int r)
{
	if(l==r)
	{
		tree[p]=arr[l];
		return; 
	}
	int mid=l+(r-l)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	tree[p]=max(tree[2*p],tree[2*p+1]);
}
void build1(int p,int l,int r)
{
	if(l==r)
	{
		tree1[p]=arr[l];
		return;
	}
	int mid=l+(r-l)/2;
	build1(2*p,l,mid);
	build1(2*p+1,mid+1,r);
	tree1[p]=min(tree1[2*p],tree1[2*p+1]);
}
int qurry(int p,int l,int r,int left,int right)
{
	if(l>=left&&r<=right)
	return tree[p];
	if(r<left||l>right)
	return -INF;
	int mid=l+(r-l)/2;
	int l1=qurry(2*p,l,mid,left,right);
	int r1=qurry(2*p+1,mid+1,r,left,right);
	return max(l1,r1);
}
int qurry1(int p,int l,int r,int left,int right)
{
	if(l>=left&&r<=right)
	return tree1[p];
	if(r<left||l>right)
	return INF;
	int mid=l+(r-l)/2;
	int l1=qurry1(2*p,l,mid,left,right);
	int r1=qurry1(2*p+1,mid+1,r,left,right);
	return min(l1,r1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	build(1,1,n);
	build1(1,1,n);
	while(q--)
	{
		int left,right;
		cin>>left>>right;
		int up=qurry(1,1,n,left,right);
		int down=qurry1(1,1,n,left,right);
		cout<<up-down<<'\n';
	}
	return 0;
	
 } 
