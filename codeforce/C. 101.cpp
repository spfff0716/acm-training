#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>arr(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		int l=1;
		int r=n;
		while(l<=n)
		{
			if(arr[l]==0)
			{
				l++;
				continue;
			}
			arr[l]=1;
			break;
		}
		while(r>l)
		{
			if(arr[r]==0)
			{
				r--;
				continue;
			}
			arr[r]=1;
			break;
		}
		for(int i=1;i<=n;i++)
		{
			if(arr[i]==-1)
			{
				cout<<0<<" ";
				continue;
			}
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
