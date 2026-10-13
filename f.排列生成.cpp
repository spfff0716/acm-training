#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int arr[N];
int main()
{
	int n,k,x;
	cin>>n>>k>>x;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int dx=(x+n-arr[k])%n;
	for(int i=0;i<n;i++)
	{
		arr[i]=(arr[i]+dx)%n;
		cout<<arr[i]<<" ";
	}
	return 0;
}
