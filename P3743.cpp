#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
double a[N],b[N];
int n;
double p;
bool check(double t)
{
	double sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]*t>b[i])
		{
			sum+=a[i]*t-b[i];
		}
	}
	return sum<=p*t;
}
int main()
{
	cin>>n>>p;
	double sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	if(p>=sum)
	{
		cout<<-1;
		return 0;
	}
	double l=0.0;
	double r=1e18;
	for(int i=0;i<200;i++)
	{
		double mid=(l+r)/2;
		if(check(mid))
		l=mid;
		else
		r=mid;
	}
	printf("%.10f",l);
	return 0;
	
 } 
