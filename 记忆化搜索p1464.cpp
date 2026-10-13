#include <bits/stdc++.h>
using namespace std;
map<vector<long long>,long long>dict;
long long res(long long a,long long b,long long c)
{
	vector<long long>arr(3);
	arr={a,b,c};
	if(a<=0||b<=0||c<=0)
	return 1;
	else if(a>20||b>20||c>20)
	return res(20,20,20); 
	else if(a<b&&b<c)
	{
		if(dict.count(arr))
		return dict[arr];
		else
		{
			dict[arr]=res(a,b,c-1)+res(a,b-1,c-1)-res(a,b-1,c);
			return dict[arr];
		}
	}
	else
	{
		if(dict.count(arr))
		return dict[arr];
		else
		{
			dict[arr]=res(a-1,b,c)+res(a-1,b-1,c)+res(a-1,b,c-1)-res(a-1,b-1,c-1);
			return dict[arr];
		}
		
	}
	
	
}
int main()
{
	long long a,b,c;
	while(true)
	{
		cin>>a>>b>>c;
		if(a==-1&&b==-1&&c==-1)
		break;
		long long result=res(a,b,c);
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<result<<endl; 
	}
	return 0;
}
