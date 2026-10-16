#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
};
int n,m;
const int N=5050;
const int M=2*1e5+10;
node bian[M];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int fa[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int find(int x)
{
	if(fa[x]!=x)
	fa[x]=find(fa[x]);
	return fa[x];
}
bool merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
	return true;
	fa[fx]=fy;
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>bian[i].x>>bian[i].y>>bian[i].z;
	}
	sort(bian,bian+m,cmp);
	init();
	int cnt=0;
	int res=0;
	for(int i=0;i<m;i++)
	{
		int nx=bian[i].x;
		int ny=bian[i].y;
		int nz=bian[i].z;
		if(merge(nx,ny))
		continue;
		else
		{
			res+=nz;
			cnt++;
		}
	}
	if(cnt==n-1)
	cout<<res;
	else
	cout<<"orz";
	return 0;
 } 
