#include <bits/stdc++.h>
using namespace std;
int arr[2000];
int num[2000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<pow(2,n);i++)
	{
		cin>>arr[i];
		num[i]=i+1;
	}
	for(int i=n-1;i>=1;i--)
	{
		int x=pow(2,i);
		for(int j=0;j<x;j++)
		{
			if(arr[2*j]>arr[2*j+1])
			{
				arr[j]=arr[2*j];
				num[j]=num[2*j];
			}
			else
			{
				arr[j]=arr[2*j+1];
				num[j]=num[2*j+1];
			}
		}
	}
	if(arr[0]>arr[1])
	cout<<num[1];
	else
	cout<<num[0];
	return 0;
 } 
