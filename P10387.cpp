#include <bits/stdc++.h>
using namespace std;
struct node{
	int p;
	int c;
	
}; 
bool cmp(node x,node y)
{
	return x.c<x.c;
}
int main()
{
	int n;
	long long s;
	cin>>n>>s;
	vector<node>arr(n);
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].p>>arr[i].c;
		sum+=arr[i].p;
	}
	long long res=0;
	sort(arr.begin(),arr.end(),cmp);
	int cnt=0;
	int nowid=0;
	while(s<sum)
	{
		res+=s*(arr[nowid].c-cnt);
		cnt=arr[nowid].c;
		sum-=arr[nowid].p;
		for(int i=nowid+1;i<n;i++)
		{
			if(arr[i].c>arr[nowid].c)
			{
				nowid=i;
				break;
			}
			sum-=arr[i].p;
		}
	}
	for(int i=nowid;i<n;i++)
	{
		res+=(arr[i].c-cnt)*arr[i].p;
	}
	cout<<res;
	return 0;
}
