#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		int res=x%7;
		if(res==0||res==2)
		{
			cout<<"ice";
		}
		else
		cout<<"Orange";
		cout<<"\n";
	}
	return 0;
}
