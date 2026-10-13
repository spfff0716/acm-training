#include <bits/stdc++.h>
using  namespace std;
int a[1010],b[1010],c[1010];
int score(int x,int y,int z)
{
	if(x==y&&y==z)
	return 200;
	if(x==y||x==z||y==z)
	return 100;
	if(y-x==1&&z-y==1)
	return 200;
	int arr[3];
	a[0]=x;
	a[1]=y;
	a[2]=z;
	sort(a,a+3);
	if(a[1]-a[0]==1&&a[2]-a[1]==1)
	return 100;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	int anow=0;
	int bnow=0;
	int cnow=0;
	int m;
	cin>>m;
	int res=0;
	while(m--)
	{
		int da,db,dc;
		cin>>da>>db>>dc;
		anow=(anow+da)%n;
		bnow=(bnow+db)%n;
		cnow=(cnow+dc)%n;
		res+=score(a[anow],b[bnow],c[cnow]);
	}
	cout<<score(3,2,4)<<endl;
	cout<<res;
	return 0;
	
}
