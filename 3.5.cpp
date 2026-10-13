#include <bits/stdc++.h> 
using namespace std; 
int main()
{
	int cnt[10]={6,2,5,5,4,5,6,3,7,6};
	int n;
	cin>>n;
	n-=4;
	int res=0;
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			int s=i+j;
			int x=i;
			int y=j;
			int sum=0;
			if(x==0)
			sum+=cnt[0];
			if(y==0)
			sum+=cnt[0]; 
			while(x>0)
			{
				sum+=cnt[x%10];
				x/=10;
			}
			while(y>0)
			{
				sum+=cnt[y%10];
				y/=10;
			}
			while(s>0)
			{
				sum+=cnt[s%10];
				s/=10;
			}
			if(sum==n)
			{
				res++; 
			}
		}
	}
	cout<<res;
	return 0;
}
