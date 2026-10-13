#include <bits/stdc++.h>
using namespace std;
int kan(vector<int>&arr)
{
	int now=arr[0];
	int res=arr[0];
	for(int i=1;i<arr.size();i++)
	{
		now=max(now+arr[i],arr[i]);
		if(now>res)
		res=now;
	}
	return res;
}
int maxres(int n,vector<vector<int>>&brr)
{
	int maxsum=INT_MIN;
	for(int up=0;up<n;up++)
	{
		vector<int>colsum(n,0);
		for(int down=up;down<n;down++)
		{
			for(int i=0;i<n;i++)
			{
				colsum[i]+=brr[down][i];
			}
			int current_max=kan(colsum);
			if(maxsum<current_max)
			{
				maxsum=current_max;
			}
		}
		
	 }
	 return maxsum;
	 
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>brr(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>brr[i][j];
		}
	}
	int res=maxres(n,brr);
	cout<<res;
	return 0;
}
