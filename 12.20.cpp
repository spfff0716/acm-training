#include <bits/stdc++.h>
using namespace std;
struct student
{
	int id;
	int chinese;
	int math;
	int english;
	int getsum() const
	{
		return chinese+math+english;
	}
};
int main()
{
	int n,i;
	cin>>n;
	vector<student> stu(n+1);
	vector<int> sum(n+1),rankid(n+1);;
	for(i=1;i<=n;i++)
	{
		rankid[i]=i; 
		stu[i].id=i;
		cin>>stu[i].chinese>>stu[i].math>>stu[i].english;
		sum[i]=stu[i].getsum();
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(sum[j]>sum[i])
			{
			swap(sum[j],sum[i]);
			swap(rankid[i],rankid[j]);}
		}
	}
	int begin=1;
	int end=1;
	while(true)
	{	
		for(int j=begin;j<n;j++)
		{
			if(sum[j]==sum[j+1])
			{
				end++;
				
			}
			else
			{
				begin++;
				end++;
				break;
			}
		}
		for(int k=begin;k<end;k++)
		{
			for(int x=k+1;x<=end;x++)
			if(stu[rankid[x]].chinese>stu[rankid[k]].chinese)
			{
			
			swap(rankid[x],rankid[k]);}
		}
		begin=end;
		if(begin>5)
		break;
	}
	for(int i=1;i<=5;i++)
	{
		cout<<rankid[i]<<" "<<stu[rankid[i]].getsum()<<endl;
	}
	
	return 0;
}
