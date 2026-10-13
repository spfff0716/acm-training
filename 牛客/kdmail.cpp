#include <bits/stdc++.h>
using namespace std;
vector<string>g[25];
string getName(int id, int cnt)
{
    string res = "";
    for(int i = 0; i < g[id].size(); i++)
    {
        if(i < cnt)
        {
            res += g[id][i];
        }
        else
        {
            res += g[id][i][0];
        }
    }
    return res;
}
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		stringstream ss(s);
		string word;
		while(ss>>word)
		{
			g[i].push_back(word);
		}
	}
	vector<int> cnt(n, 0);
    vector<bool> locked(n, false);
    vector<string> now(n);
    int lockedCnt = 0;
    while(lockedCnt < n)
    {
        map<string, int> mp;
        for(int i = 0; i < n; i++)
        {
            now[i] = getName(i, cnt[i]);
            mp[now[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(locked[i])
            continue;
            if(mp[now[i]] == 1)
            {
                locked[i] = true;
                lockedCnt++;
            }
            else
            {
                if(cnt[i] < g[i].size())
                {
                    cnt[i]++;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << getName(i, cnt[i]) << '\n';
    }
	return 0;
 } 
