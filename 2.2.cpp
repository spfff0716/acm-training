#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<string> cnt(n);
	getline(cin,cnt[0]);
	int max_len=cnt[0].length();
	int max_id=0;
	for(int i=0;i<n;i++)
	{
		getline(cin,cnt[i]);
		int now=cnt[i].length();
		if(now>max_len)
		{
			max_len=now;
			max_id=i;
		}
		else if(now==max_len)
		{
			for(int k=0;k<now;k++)
			{
				if(cnt[max_id][k]>cnt[i][k])
				break;
				if(cnt[max_id][k]<cnt[i][k])
				{
					max_id=i;
					break;
				}
			}
		}
	}
	cout<<max_id+1<<endl<<cnt[max_id];
	return 0;
}
