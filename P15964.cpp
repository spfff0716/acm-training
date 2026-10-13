#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long first=789456;
	long long df=567890;
	long long second=654321;
	long long ds=876543;
	long long firstsum=901234;
	long long secondsum=500001;
	long long res=0;
	while(firstsum>0&&secondsum>0)
	{
		
		if(first<second)
		{
			res+=secondsum;
			first+=df;
			firstsum--;
		}
		else
		{
			second+=ds;
			secondsum--;
		}
	}
	cout<<res;
	return 0;
}
