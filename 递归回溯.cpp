#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[30];
int cnt=0;
vector<int> path;
bool  isprime(int num)
{
	if(num<=1)
	return false;
	if(num==2)
	return true;
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0)
		return false;
	 } 
	 return true;
}
void combine(int start)
{
	int sum=0;
	if(path.size()==k)
	{
		for(int i=0;i<k;i++)
		sum+=a[path[i]];
		if(isprime(sum))
		cnt++;
		return;
	}
	for(int i=start;i<=n;i++)
	{
		path.push_back(i);
		combine(i+1);
		path.pop_back();
	}
	return;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	combine(1);
	cout<<cnt;
	return 0;
	
}
