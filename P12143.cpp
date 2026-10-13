#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool nice(int l,int r)
{
	if(l==r)
	return true;
	int cnt=0;
	for(int i=l+1;i<=r;i++)
	{
		int dx=a[i]-a[i-1];
		if(dx==0||dx==1)
		continue;
		cnt++;
		if(cnt==2)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int x;
	string s;
	cin>>s;
	int n=s.size();
	long long res=0;
	for(int i=0;i<n;i++)
	{
		a[i]=s[i]-'0';
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(nice(i,j))
			res++;
			else
			break;
		}
	}
	cout<<res;
	return 0;
}

