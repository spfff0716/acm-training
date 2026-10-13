#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,r;
}cir[1005];
int n;
bool check(int nx,int ny)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int s=(nx-cir[i].x)*(nx-cir[i].x)+(ny-cir[i].y)*(ny-cir[i].y);
		if(s<=cir[i].r*cir[i].r)
		cnt++;
	}
	if(cnt%2==1)
	return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>cir[i].x>>cir[i].y>>cir[i].r;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int nx,ny;
		cin>>nx>>ny;
		if(check(nx,ny))
		cout<<"YES";
		else
		cout<<"NO";
		cout<<'\n';
	}
	return 0;
}
