#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int fa[2010];
struct node
{
	int u,v;
	long long cost;
};
bool cmp(node x,node y)
{
	return x.cost<y.cost;
}
int find(int x)
{
	if(fa[x]!=x)
	fa[x]=find(fa[x]);
	return fa[x];
}
bool uni(int x,int y)
{
	int nx=find(x);
	int ny=find(y);
	if(nx!=ny)
	{
		fa[nx]=ny;
		return true;
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	vector<pii>place(n+1);
	for(int i=0;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		place[i]={x,y};	
	}
	vector<node>brr;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
		brr.push_back({0,i,c});
	}
	vector<long>krr(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>krr[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			int dx=abs(place[i].first-place[j].first);
			int dy=abs(place[i].second-place[j].second);
			long w=(dx+dy)*(krr[i]+krr[j]);
			brr.push_back({i,j,w});
		}
	}
	sort(brr.begin(),brr.end(),cmp);
	int cnt=0;
	long long ans=0;
	int res2=0;
	vector<int>res3;
	int res4=0;
	vector<pii>res5;
	for(int i=0;i<brr.size();i++)
	{
		if(uni(brr[i].u,brr[i].v))
		{
			if(brr[i].u==0)
			{
				res2++;
				res3.push_back(brr[i].v);
			}
			else
			{
				res4++;
				res5.push_back({brr[i].u,brr[i].v});
			}
			ans+=brr[i].cost;
			cnt++;
		}
		if(cnt==n)
		break;
	}
	cout<<ans<<endl;
	cout<<res2<<endl;
	for(int i=0;i<res3.size();i++)
	{
		cout<<res3[i]<<" ";
	}
	cout<<endl;
	cout<<res4<<endl;
	for(int i=0;i<res5.size();i++)
	{
		cout<<res5[i].first<<" "<<res5[i].second<<endl;
	}
	return 0;
 } 
