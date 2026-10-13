#include <bits/stdc++.h>
using namespace std;
bool cmp(string x,string y)
{
	return x+y>y+x;
}
int main()
{
	int n;
	cin>>n;
	vector<string>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
	return 0;
 } 
