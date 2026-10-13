#include <bits/stdc++.h>
using namespace std;
unordered_set<int>a={1,3,5,7,8,10,12};
bool isrun(int year)
{
	if(year%4==0&&(year%100!=0||year%400==0))
	return true;
	return false;
}
int daynum(int year,int month)
{
	if(month==2)
	{
		if(isrun(year))
		return 29;
		else
		return 28;
	}
	else if(a.count(month))
	return 31;
	return 30;
}
bool lucky(int year,int month,int day)
{
	vector<int>arr;
	int l=0;
	int x;
	while(year>0)
	{
		x=year%10;
		year/=10;
		arr.push_back(x);
		l++;
	}
	while(month>0)
	{
		x=month%10;
		month/=10;
		arr.push_back(x);
		l++;
	}
	while(day>0)
	{
		x=day%10;
		day/=10;
		arr.push_back(x);
		l++;
	}
	sort(arr.begin(),arr.end());
	int cnt[10]={0};
	for(int i=0;i<l;i++)
	{
		cnt[arr[i]]++;
	}
	int ct;
	for(int i=0;i<10;i++)
	{
		if(cnt[i]!=0)
		{
			ct=cnt[i];
			break;
		}
	}
	for(int i=0;i<10;i++)
	{
		if(cnt[i]!=0)
		{
			if(ct!=cnt[i])
			return 0;
		}
		
	}
	return true;

	
}
int main()
{
	int year=2239;
	int month=9;
	int day=9;
	long long res=0;
	for(;day<=daynum(year,month);day++)
		{
			if(lucky(year,month,day))
			res++;
		}
	for(int month=10;month<=12;month++)
	{
		for(int day=1;day<=daynum(year,month);day++)
		{
			if(lucky(year,month,day))
			res++;
		}
	}
	for(int year=2240;year<=9875;year++)
	{
		for(int month=1;month<=12;month++)
		{
			for(int day=1;day<=daynum(year,month);day++)
			{
				if(lucky(year,month,day))
				res++;
			}
		}
	}
	cout<<res;
	


	return 0;
}
