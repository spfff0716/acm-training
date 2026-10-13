#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,country,sum;
	long long time;
	map<int,long long>passage; 
	multiset<long long>times; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>time>>sum;
		for(int j=1;j<=sum;j++)
		{
			cin>>country;
			if (passage.count(country)) {
    auto it = times.find(passage[country]);
    if (it != times.end()) {
        times.erase(it);  
    }
}
			times.insert(time);
			passage[country]=time;
		}
		while(!times.empty()&&time-*times.begin()>86400)
		{
			times.erase(times.begin());
		}
		cout<<times.size()<<"\n";
		}
		
	
	return 0;
}
