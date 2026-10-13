#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+10; 
int a[N];
int random(int left,int right)
{
	return a[rand()%(right-left+1)+left];
}
void quick(int left,int right)
{
	if(left>=right)
	return;
	int p=random(left,right);
	int l=left-1;
	int i=left;
	int r=right+1;
	while(i<r)
	{
		if(p>a[i])
		{
			swap(a[++l],a[i]);
			i++;
		}
		else if(p==a[i])
		{
			i++;
		}
		else
		{
			swap(a[--r],a[i]);
		}
	}
	quick(left,l);
	quick(r,right);
	return;
}
int main()
{
	srand(time(0));
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	quick(1,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	return 0; 
 } 
