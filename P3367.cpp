#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int fa[N];
int n,m;
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int find(int x)
{
	if(fa[x]==x)
	return fa[x];
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y)
{
	if(find(x)==find(y))
	return true;
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy;
	return false;
}
int main()
{
	cin>>n>>m;
	init();
	while(m--)
	{
		int z,x,y;
		cin>>z>>x>>y;
		if(z==1)
		{
			merge(x,y);
		}
		else
		{
			if(find(x)==find(y))
			{
				cout<<"Y";
			}
			else
			cout<<"N";
			cout<<endl;
		}
	}
}
