#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>cnt(n);
	for(int i=0;i<n;i++)
	{
		cin>>cnt[i]; 
	}
	long long res=0;
	while(n>1)
	{
		int min1=0;
		int min2=1;
		if(cnt[min1]>cnt[min2])
		swap(min1,min2);
		for(int i=2;i<n;i++)
		{
			if(cnt[i]<cnt[min1])
			{
			min2=min1;
			min1=i;
			}
			else if(cnt[i]<cnt[min2])
			min2=i;
			
		}
		int sum=cnt[min1]+cnt[min2];
		res+=sum;
		cnt[min1]=sum;
		cnt[min2]=cnt[n-1];
		n--;
	}
	cout<<res;
	return 0;
 } 
