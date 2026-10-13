#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int in[N];
int cost[N],dp[N];
// 删掉全局的 vector<int> g[N];
int n;

int main()
{
    cin>>n;
    // 在这里动态创建二维vector，大小n+1
    vector<vector<int>> g(n+1);
    
    for(int i=1;i<=n;i++)
    {
        int id,pre;
        cin>>id>>cost[id];
        dp[id]=cost[id];
        while(true)
        {
            cin>>pre;
            if(pre==0) break;
            in[id]++;
            g[pre].push_back(id);  // 用法完全一样
        }
    }

    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0) q.push(i);
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            dp[v]=max(dp[v],dp[u]+cost[v]);
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}

