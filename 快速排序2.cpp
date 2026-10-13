#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int random(int left,int right)
{
	return a[rand()%(right-left+1)+left];
}
void quicksort(int left,int right)
{
	if(left>=right)
	return; 
	int p=random(left,right);
	int l=left-1;
	int i=left;
	int r=right+1;
	while(i<r)
	{
		if(a[i]<p)
		{
			swap(a[++l],a[i]);
			i++;
		}
		else if(a[i]==p)
		i++;
		else
		{
			swap(a[i],a[--r]);
		}
	}
	quicksort(left,l);
	quicksort(r,right);
	return; 
}
int main()
{
	srand(time(0));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	quicksort(1,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" "; 
	return 0;
 } 
