#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int arr[N];
long long res(int left,int right)
{
	if(right-left<=1)
	return 0;
	if(right-left==2)
	return arr[left+1];
	long long sum=0;
	int smallest=arr[left+1];
	for(int i=left+1;i<right;i++)
	{
		if(arr[i]<smallest)
		smallest=arr[i];
	}
	int l=left;
	int r=left;
	sum+=smallest;
	for(int i=left+1;i<right;i++)
	{
		if(arr[i]==smallest)
		{
			r=i;
		 } 
		else
		arr[i]-=smallest;
		sum+=res(l,r);
		l=r;
		
		
	}
	sum+=res(l,right);
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	random_shuffle(arr+1, arr+n);
	long long day=res(0,n+1);
	cout<<day;
	return 0;
 } 
