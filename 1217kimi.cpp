#include <bits/stdc++.h>
#include <vector>
using namespace std;
int panduan(int x,int y)
{
	if(x==y)
	return 0;
	if((x==0&&(y==2||y==3))||(x==1&&(y==0||y==3))||(x==2&&(y==1||y==4))||(x==3&&(y==2||y==4))||(x==4&&(y==0||y==1)))
	return 1;
	return 2;
 } 
int main()
{
	int n,na,nb;
	cin>>n>>na>>nb;
	int cnta=0;
	int cntb=0;
	vector<int> a,b;
	int m;
	for(int i=0;i<na;i++)
	{
		cin>>m;
		a.push_back(m);
	}
	for(int i=0;i<nb;i++)
	{
		cin>>m;
		b.push_back(m);
	}
	for(int i=0;i<n;i++)
	{
		int ai=i%na;
		int bi=i%nb;
		int pan=panduan(a[ai],b[bi]);
		if(pan==1)
		cnta++;
		else if(pan==2)
		cntb++;
	}
	cout<<cnta<<" "<<cntb;
	return 0;
}
