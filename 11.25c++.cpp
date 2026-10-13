#include <iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int cnt=0;
	for(;;)
	{
		
		
		if(a==1)
        break;
		a=a/2;
		cnt++;		
	}
	cout<<cnt;
	return 0;
}
