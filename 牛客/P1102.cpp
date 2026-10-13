#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long c;
	cin>>n>>c;
	vector<long long>arr(n);
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	int l=0;
	for(int r=1;r<n;r++)
	{
		while(arr[r]-arr[l]>c)
		{
			l++;
		}
		if(arr[r]-arr[l]<c)
		continue;
		int left=1;
		int right=1;
		while(l+1<n-1&&arr[l]==arr[l+1])
		{
			l++;
			left++;
		}
		while(r+1<n&&arr[r]==arr[r+1])
		{
			r++;
			right++;
		}
		ans+=left*right;
	}
	cout<<ans;
}
