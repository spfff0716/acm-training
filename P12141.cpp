#include <bits/stdc++.h>
using namespace std;
bool find(int n,long long k)
{
	if(n==1&&k==1)
	return true;
	if(k%2==1)
	{
		return find(n-1,(k+1)/2);
	}
	else
	{
		return !find(n-1,(k+1)/2);
	}
}
int main()
{
	int m;
	cin>>m;
	while(m--)
	{
		int n;
		long long k;
		cin>>n>>k;
		if(find(n,k))
		cout<<"RED";
		else
		cout<<"BLACK";
		cout<<endl;
	}
	return 0;
}
