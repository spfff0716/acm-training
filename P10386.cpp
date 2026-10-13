#include <bits/stdc++.h>
using namespace std;
long long res=0;
int arr[10][10];
bool win()
{
	int x=0,y=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			x+=arr[i][j];
		}
		if(x==5||x==0)
		return true;
		x=0;
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			x+=arr[j][i];
		}
		if(x==5||x==0)
		return true;
		x=0;
	}
	for(int i=0;i<5;i++)
	{
		x+=arr[i][i];
	}
	if(x==5||x==0)
	return true;
	x=0;
	for(int i=0;i<5;i++)
	{
		x+=arr[i][4-i];
	}
	if(x==5||x==0)
	return true;
	return false;
}
void dfs(int pos,int white,int black)
{
	if(win())
	return;
	if(pos==25)
	{
		res++;
		return;
	}
	if(white>0)
	{
		arr[pos/5][pos%5]=0;
		dfs(pos+1,white-1,black);
		arr[pos/5][pos%5]=-10;
	}
	if(black>0)
	{
		arr[pos/5][pos%5]=1;
		dfs(pos+1,white,black-1);
		arr[pos/5][pos%5]=-10;
	}
}
int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		arr[i][j]=-10;
	}
	dfs(0,13,12);
	cout<<res;
	return 0;
 } 
