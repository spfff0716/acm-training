#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	string names[n];
	int direct[n];
	int i;
	for(i=0;i<n;i++)
	{
		cin>>direct[i]>>names[i];
		
	}
	int d,l,toy=0;
	for(i=0;i<m;i++)
	{
		cin>>d>>l;
		if((direct[toy]==0&&d==1)||(direct[toy]==1&&d==0))
		{
			toy=(toy+l)%n;
		}
		else
		{
			toy=toy-l;
			if(toy<0)
			toy=toy+n;
		}
	}
	cout<<names[toy];
	return 0;
}
