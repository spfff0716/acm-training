#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int temp[N];
void sort(int left,int right)
{
	if(left>=right)
	return;
	int mid=(right-left)/2+left;
	int i=left;
	int idx=left;
	int idy=mid+1;
	sort(left,mid);
	sort(mid+1,right);
	while(idx<=mid&&idy<=right)
	{
		if(a[idx]<=a[idy])
		temp[i++]=a[idx++];
		else
		temp[i++]=a[idy++];
	}
	while(idx<=mid)
	temp[i++]=a[idx++];
	while(idy<=right)
	temp[i++]=a[idy++];
	for(int i=left;i<=right;i++)
	{
		a[i]=temp[i];
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(1,n);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	return 0;
 } 
