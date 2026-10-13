#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int word;
	list<int> dict;
	unordered_map<int, list<int>::iterator> pos;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>word;
		if(pos.count(word))
		{
			continue;
		}
	  
	 cnt++;
	 if(dict.size()==m)
	 {
	 	int oldest=dict.front();
	 	dict.pop_front();
	 	pos.erase(oldest);
	 }
	 dict.push_back(word);
	 pos[word]=dict.end();
}
    cout<<cnt;
    return 0;
}
