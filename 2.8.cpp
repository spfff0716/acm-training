#include <bits/stdc++.h>
using namespace std;
vector<int> path;
int n,m;
int small=3000;
vector<int>white;
vector<int>blue;
vector<int>red;
int white_sum[100];
int blue_sum[100];
int red_sum[100];
void res(int start)
{
	if(path.size()==2)
	{
		int sum=m*n-white_sum[path[0]]-(blue_sum[path[1]]-blue_sum[path[0]])-(red_sum[n-1]-red_sum[path[1]]);
		if(sum<small)
		small=sum;
		return;
	}
	for(int i=start;i<n;i++)
	{
		if (path.size() == 0 && i > n-3) break;
		if (path.size() == 1 && i > n-2) break;
		path.push_back(i);
		res(i+1);
		path.pop_back();
	}
}
int main()
{
	cin>>n>>m;
	char ch;
	white.resize(n,0);
	blue.resize(n,0);
	red.resize(n,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>ch;
			if(ch=='W')
			white[i]++;
			if(ch=='R')
			red[i]++;
			if(ch=='B')
			blue[i]++;
			
		}
	}
	white_sum[0]=white[0];
	for(int i=1;i<n;i++)
	{
		white_sum[i]=0;
		white_sum[i]=white_sum[i-1]+white[i];
	}
	blue_sum[0]=blue[0];
	for(int i=1;i<n;i++)
	{
		blue_sum[i]=0;
		blue_sum[i]=blue_sum[i-1]+blue[i];
	}
	red_sum[0]=red[0];
	for(int i=1;i<n;i++)
	{
		red_sum[i]=0;
		red_sum[i]=red_sum[i-1]+red[i];
	}
	res(0);
	cout<<small;
	return 0;
	
 } 
