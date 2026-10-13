#include <bits/stdc++.h>
using namespace std;
int main()
{
	for(int j=1;j<=50;j++)
	{
		for(int i=1;i<=50;i++)
		{
			if(i%j+1==i%(j+1))
			{
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
}

