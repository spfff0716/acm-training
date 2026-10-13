#include <bits/stdc++.h>
using namespace std;
bool next(int *first,int *last)
{
	if(first==last)
	return false;
	int *i=last-1;
	if(first==i)
	return false;
	while(true)
	{
		int *j=i;
		i--;
		if(*i<*j)
		{
			int *k=last-1;
			while(*i>=*k)
			{
				k--;
			}
			swap(*i,*k);
			reverse(j,last);
			return true;
			
		}
		if(i==first)
		{
			reverse(first,last);
			return false;
	}
}}
int main()
{
	int flag=0
	int num[] = {1,2,3,4,5,6,7,8,9};
	int a,b,c;
	cin>>a>>b>>c;
	do
	{
		int x=num[0]*100+num[1]*10+num[2];
		int y=num[3]*100+num[4]*10+num[5];
		int z=num[6]*100+num[7]*10+num[8];
		if(b*x==y*a&&c*x==z*a)
		{
			cout<<x<<" "<<y<<" "<<z<<endl;
			flag=1;
		}
	}while(next(num,num+9));
	if(flag==0)
	cout<<"No!!!";
	return 0;
}
