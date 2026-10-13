#include <bits/stdc++.h>
using namespace std;
int arr[300];
int ans[300];
int main()
{
	string s;
	int k;
	cin>>s>>k;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		arr[i]=s[i]-'0';
	}
	int nowid=0;
	int minid=0;
	int id=0;
	while(k>0&&nowid<n)
	{
		minid=nowid;
		int r=min(nowid+k,n-1);
		for(int i=nowid;i<=r;i++)
		{
			if(arr[i]<arr[minid])
			{
				minid=i;
			}
		}
		ans[id]=arr[minid];
		id++;
		k=k-(minid-nowid);
		minid++;
		nowid=minid; 
	}
	for(int i=nowid;i<s.size();i++)
	{
		ans[id]=arr[i];
		id++;
	}
	int flag1=1;
	int flag2=1;
	for(int i=0;i<id;i++)
	{
		if(flag1==1)
		{
			if(ans[i]==0)
			continue;
			else
			flag1=0;
		}
		cout<<ans[i];
		flag2=0;
	}
	if(flag2==1)
	{
		cout<<0;
	}
	return 0;
	
 } 
