#include <bits/stdc++.h>
using namespace std;
int main()
{
	unordered_set<int>arr={0,1,4,5,6,9};
	int n=1;
	int cnt=0;
	while(true)
	{
		int sum1=2*n+1;
		int x1=int(sqrt(sum1));
		int sum2=3*n+9;
		int x2=int(sqrt(sum2));
		if((x1*x1==sum1)&&(x2*x2==sum2))
		{
			cout<<n<<endl;
			cnt++;
			if(cnt==10)
			break;
		}
		n++;
	}
	return 0;
}


