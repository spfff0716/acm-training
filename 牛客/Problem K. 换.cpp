#include <bits/stdc++.h>
using namespace std;
int mex(int a,int b,int c)
{
	if(a!=0&&b!=0&&c!=0)
	return 0;
	else if(a!=1&&b!=1&&c!=1)
	return 1;
	else if(a!=2&&b!=2&&c!=2)
	return 2;
	return 3;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>arr(n+2);
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	arr[0]=arr[n];
	arr[n+1]=arr[1];
	if(k<=10)
	{
		vector<int>brr(n+2);
		while(k--)
		{
			for(int i=1;i<=n;i++)
			{
				brr[i]=mex(arr[i-1],arr[i],arr[i+1]);
			}
			for(int i=1;i<=n;i++)
			{
				arr[i]=brr[i];
			}
			arr[0]=arr[n];
			arr[n+1]=arr[1];
		} 
	}
	else
	{
		vector<int>brr(n+2);
		if(k%2==1)
		{
			int a=9;
			while(a--)
			{
				for(int i=1;i<=n;i++)
				{
					brr[i]=mex(arr[i-1],arr[i],arr[i+1]);
				}
				for(int i=1;i<=n;i++)
				{
					arr[i]=brr[i];
				}
				arr[0]=arr[n];
				arr[n+1]=arr[1];
			}
		}
		else
		{
			int a=10;
			while(a--)
			{
				for(int i=1;i<=n;i++)
				{
					brr[i]=mex(arr[i-1],arr[i],arr[i+1]);
				}
				for(int i=1;i<=n;i++)
				{
					arr[i]=brr[i];
				}
				arr[0]=arr[n];
				arr[n+1]=arr[1];
			}
		}
	}
	for(int i=1;i<=n;i++)
		{
			cout<<arr[i]<<" ";
		 }
	return 0;
 } 
