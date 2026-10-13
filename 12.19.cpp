#include <bits/stdc++.h>
using namespace std;
int main()
{
	set<int> a;
	int n,k,x;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.insert(x);
	}
	auto it = a.begin();
    advance(it, k);
	cout<<*it;
	return 0;
}
