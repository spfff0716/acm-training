#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		double x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int i=3;i<=n;i++)
		{
			double x3,y3;
			cin>>x3>>y3;
			double cross=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
			if(cross>0)
			{
				cout<<"LEFT";
			}
			else if(cross<0)
			{
				cout<<"RIGHT";
			}
			else
			{
				cout<<"STRAIGHT"; 
			}
			cout<<" ";
			x1=x2;
			y1=y2;
			x2=x3;
			y2=y3;
		}
		cout<<'\n';
	}
	return 0;
 } 
