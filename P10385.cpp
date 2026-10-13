#include <bits/stdc++.h>
using namespace std;
set<int>a={1,3,5,7,8,10,12};
int nums[]={13,1,2,3,5,4,4,2,2,2};
bool isrun(int year)
{
	if(year%400==0)
	return true;
	else if(year%100==0)
	return false;
	else if(year%4==0)
	return true;
	return false;
}
int days(int year,int month)
{
	if(month==2)
	{
		if(isrun(year))
		return 29;
		else
		return 28;
	}
	else if(a.count(month))
	{
		return 31; 
	}
	return 30;
}
bool lanqiu(int year,int month,int day)
{
	int cnt=0;
	int sum=0;
	while(year>0)
	{
		int x=year%10;
		sum+=nums[x];
		year/=10;
		cnt++;
	}
	while(month>0)
	{
		int x=month%10;
		sum+=nums[x];
		month/=10;
		cnt++;
	}
		while(day>0)
	{
		int x=day%10;
		sum+=nums[x];
		day/=10;
		cnt++;
	}
	sum+=(8-cnt)*nums[0];
	if(sum>50)
	return true;
	return false;
	
}
int main()
{
	int res=0;
	for(int year=2000;year<=2023;year++)
	{
		for(int month=1;month<=12;month++)
		{
			for(int day=1;day<=days(year,month);day++)
			{
				if(lanqiu(year,month,day))
				res++;
			}
		}
	}
	for(int month=1;month<=3;month++)
	{
		for(int day=1;day<=days(2024,month);day++)
		{
			if(lanqiu(2024,month,day))
			res++;
		}
	}
	for(int day=1;day<=13;day++)
	{
		if(lanqiu(2024,4,day))
		res++;
	}
	cout<<res;
	return 0;
 } 
