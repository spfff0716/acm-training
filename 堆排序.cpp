#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
void heapify(int size,int i)
{
	while(true)
	{
		int largest=i;
		int left=2*i+1;
		int right=2*i+2;
		if(left<size&&a[left]>a[largest])
		largest=left;
		if(right<size&&a[right]>a[largest])
		largest=right;
		if(largest==i)
		break;
		swap(a[largest],a[i]);
		i=largest;
	}
}
void sort(int size)
{
	for(int i=size/2-1;i>=0;i--)
	{
		heapify(size,i);
	}
	for(int i=size-1;i>0;i--)
	{
		swap(a[0],a[i]);
		heapify(i,0);
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(n);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
