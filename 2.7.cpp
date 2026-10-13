#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	while(m--)
	{
		int k=n-1;
		while(true)
		{
			int j=k;
			k--;
			if(a[k]<a[j])
			{
				int l=n-1;
				while(a[k]>=a[l])
				l--;
				swap(a[k],a[l]);
				reverse(a.begin()+j,a.end());
				break;
			}
			
		}
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
		
 } 
