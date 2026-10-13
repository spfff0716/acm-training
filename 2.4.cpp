#include <bits/stdc++.h>
using namespace std;
bool next(int *first,int *last)
{
	if(first==last)
	return false;
	int *i=last-1;
	if(first==i)
	return false;
	while(true)
	{
		int *j=i;
		i--;
		if(*i<*j)
		{
			int *k=last-1;
			while(*i>=*k)
			{
				k--;
			}
			swap(*i,*k);
			reverse(j,last);
			return true;
			
		}
		if(i==first)
		{
			reverse(first,last);
			return false;
	}
}}
int main()
{
	int n,j,k;
	cin>>n;
	if(n<10||n>30)
	{
		cout<<"0";
		return 0;
	}
	int a[10];
	int b[10000][10];
	int cnt=9;
	int sum=n;
	for(int i=0;i<10;i++)
	{
		if(sum-3*cnt<=1)
		a[i]=1;
		else if(sum-3*cnt==2)
		a[i]=2;
		else
		a[i]=3;
		sum=sum-a[i];
		cnt--;
	}
	for(int i=0;i<10;i++)
	{
		b[0][i]=a[i];
	}
	int res=0;
	int id=0;
	while(true){
		if(b[id][0]==1&&b[id][9]==3)
		{
			int j=9;int k=9;
			while(true)
			{
				if(b[id][j]<3)
				break;
				j--;
			}
			while(true)
			{
				if(b[id][k]==1)
				break;
				k--;
			}
			j++;
			
		}
		for(int i=0;i<10;i++)
		{
			if(i==j)
			b[id+1][i]==b[id][i]-1;
			else if(i==k)
			b[id+1][i]==b[id][i]+1;
			else
			b[id+1][i]==b[id][i];
		}
		
		do
		{
			res++;
		}while(next(b[id],b[id]+10));
		if(b[id][0]!=1||b[id][9]!=3)
		break;
		id++;
		
		
	}
	cout<<res<<endl;
	for(int i=0;i<10;i++)
	{
		b[0][i]=a[i];
	}
	id=0;
	while(true){
		
		if(b[id][0]==1&&b[id][9]==3)
		{
			int j=9;int k=9;
			while(true)
			{
				if(b[id][j]<3)
				break;
				j--;
			}
			while(true)
			{
				if(b[id][k]==1)
				break;
				k--;
			}
			j++;
			
		}
		for(int i=0;i<10;i++)
		{
			if(i==j)
			b[id+1][i]==b[id][i]-1;
			else if(i==k)
			b[id+1][i]==b[id][i]+1;
			else
			b[id+1][i]==b[id][i];
		}
		do
		{
			for(int i=0;i<10;i++)
			{
				cout<<b[id][i]<<" ";
			}
			cout<<endl;
		}while(next(b[id],b[id]+10));
		if(b[id][0]!=1||b[id][9]!=3)
		break;
		id++;
		
		
	}
	return 0;

}
