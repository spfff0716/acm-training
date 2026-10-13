#include <bits/stdc++.h>
using namespace std;
int main()
{
	int v,n;
	cin>>v>>n;
	vector<bool>res(v+1,false);
	res[0]=true;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=v;j>=arr[i];j--)
		{
			if(res[j-arr[i]])
			res[j]=true;
		}
	}
	int sum;
	for(int j=v;j>0;j--)
	{
		if(res[j])
		{
			sum=j;
			break;
		}
	}
	cout<<v-sum;
	return 0;
}
