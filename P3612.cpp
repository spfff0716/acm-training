#include <bits/stdc++.h>
using namespace std;
int main()
{
	string ch;
	long long n;
	cin>>ch>>n;
	long long l=ch.size();
	while(l<=n)
	{
		ch.push_back(ch[l-1]);
		ch.append(ch.substr(0, l - 1));
		l=ch.size();
	}
	cout<<ch[n-1]<<endl;
	return 0;
	
}
