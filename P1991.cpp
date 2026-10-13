#include <bits/stdc++.h>
using namespace std;
const int N=3*1e6;
struct node
{
	int u,v;
	double d;
}tree[N];
int fi[505];
int arr[505][2];
int find(int x)
{
	if(fi[x]==x)
	return x;
	fi[x]=find(fi[x]);
	return fi[x];
}
bool combine(int x,int y)
{
	int nx=find(x);
	int ny=find(y);
	if(nx==ny)
	return true;
	fi[nx]=ny;
	return false;
}
bool cmp(node x,node y)
{
	return x.d<y.d;
}
int main()
{
	int s,p;
	cin>>s>>p;
	for(int i=1;i<=p;i++)
	{
		fi[i]=i;
	}
	for(int i=1;i<=p;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	int sum=0;
	for(int i=1;i<=p;i++)
	{
		for(int j=i+1;j<=p;j++)
		{
			tree[sum].u=i;
			tree[sum].v=j;
			int dx=arr[i][0]-arr[j][0];
			int dy=arr[i][1]-arr[j][1];
			tree[sum].d=sqrt(dx*dx+dy*dy);
			sum++;
		}
	}
	sort(tree,tree+sum,cmp);
	int cnt=0;
	double ans=0;
	for(int i=0;i<sum;i++)
	{
		int x=tree[i].u;
		int y=tree[i].v;
		double z=tree[i].d;
		if(combine(x,y))
		continue;
		cnt++;
		ans=z;
		if(cnt==p-s)
		break;
	}
	printf("%.2f",ans);
	return 0;
 } 
