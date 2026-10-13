#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N];
int n;
long long res=0;
vector<int>brr;
void isyin()
{
	vector<int>brr1=brr;
	sort(brr1.begin(),brr1.end());
	if(brr1[1]%brr1[0]==0&&brr1[3]%brr1[2]==0)
	{
		int x=2;
		if(brr1[1]==brr1[0])
		x*=2;
		if(brr1[3]==brr1[2])
		x*=2;
		res+=x;
	}
	if(brr1[2]%brr1[0]==0&&brr1[3]%brr1[1]==0)
	{
		int x=2;
		if(brr1[2]==brr1[0])
		x*=2;
		if(brr1[3]==brr1[1])
		x*=2;
		res+=x;
	}
	if(brr1[2]%brr1[1]==0&&brr1[3]%brr1[0]==0)
	{
		int x=2;
		if(brr1[1]==brr1[2])
		x*=2;
		if(brr1[3]==brr1[0])
		x*=2;
		res+=x;
	}
	return;
 } 
void dfs(int now)
{
	if(brr.size()==4)
	{
		isyin();
		return;
	}
	for(int i=now;i<n;i++)
	{
		brr.push_back(arr[i]);
		dfs(i+1);
		brr.pop_back();
		
	}
	return;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dfs(0);
	cout<<res;
	return 0;

	
	
 } 
