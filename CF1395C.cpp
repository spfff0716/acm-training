#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>arr(n);
	vector<int>brr(m);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>brr[i];
	}
	int ans=0;
	
	while(ans<512)
	{
		int ok=1;
		for(int i=0;i<n;i++)
		{
			int flag=1;
			for(int j=0;j<m;j++)
			{
				if(((arr[i]&brr[j])|ans)==ans)
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				ok=0;
				break;
			}
		}
		if(ok)
		break;
		else
		ans++;
	}
	cout<<ans;
	return 0;
 } 
 
