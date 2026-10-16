#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		if(b>=a)
		{
			cout<<-1<<endl;
			continue;
		}
		else
		{
			if(a>=2*b)
			{
				cout<<b<<endl;
			}
			else
			{
				cout<<2*b-a<<endl;
			}
		}
	}
	return 0;
 } 
