#include <bits/stdc++.h>
using namespace std;
int f[5050];
int find(int x)
{
	if(f[x]==x)
	return x;
	f[x]=find(f[x]);
	return f[x];
}
void mergeset(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	f[fx]=fy;
}
int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	int x,y;
	while(m--)
	{
		cin>>x>>y;
		mergeset(x,y);
	}
	while(p--)
	{
		cin>>x>>y; 
		if(find(x)==find(y))
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
	
}
