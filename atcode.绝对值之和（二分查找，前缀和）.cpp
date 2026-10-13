#include <bits/stdc++.h>
using namespace std;
int search(long a,vector<long long>&b)
{
	if(a<b[0])
	return 0;
	if(a>b[b.size()-1])
	return b.size();
	long left=0;
	long right=b.size()-1;
	long idex=(left+right)/2;
	while (left < right) {
        int mid = left + (right - left) / 2;  
        
        if (b[mid] <= a) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
	return left;
}
int main()
{
	long long n,m;
	long long sum=0;
	cin>>n>>m;
	vector<long long>pre(m+1),nex(m+1);
	vector<long long>a(n),b(m);
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<m;i++)
	cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	pre[0]=0;
	nex[m]=0;
	for(int i=1;i<=m;i++)
	{
		pre[i]=pre[i-1]+b[i-1];
		nex[m-i]=nex[m-i+1]+b[m-i];
	}
	for(int i=0;i<n;i++)
	{
		long idex=search(a[i],b);
		sum=sum+(a[i]*idex-pre[idex])+(nex[idex]-a[i]*(m-idex));
		sum%=998244353;
	}
	cout<<sum;
	
	return 0;
 } 
