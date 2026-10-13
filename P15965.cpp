#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int main()
{
	int t;
	cin>>t;
	int a,b;
	while(t--)
	{
		int n,x;
		int flag=1;
		cin>>n>>x;
		cin>>a;
		for(int i=1;i<n;i++)
		{
			cin>>b;
			if(b-a>1||a-b>x)
			{
				flag=0;
				cout<<"Lose";
				break;
			}
			a=b;
		}
		if(flag)
		cout<<"Win";
	}
	return 0;
 } 
