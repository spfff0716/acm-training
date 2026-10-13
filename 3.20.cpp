#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	cin>>n>>x;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int res=0;
	for(int i=1;i<n;i++)
	{
		while((arr[i]+arr[i-1]>x)&&arr[i]>0)
		{
			arr[i]--;
			res++;
		}
	}
	while(arr[0]+arr[1]>x)
	{
		arr[0]--;
		res++;
	}
	cout<<res;
	return 0;
}
