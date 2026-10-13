#include <bits/stdc++.h>
#define int long long
using namespace std;
int P=998244353;

int dfs(int a,int min){
	if(a==0) return 1;
	int count=0;	
	for(int i=min;i<=a;i++){
		count+= dfs(a-i,i);
	}
	return count;
}

void solve() {
	int n,c;
	cin >>n>>c;
	vector<int> ci(n+1,c);
	for(int i=2;i<=n;i++){
		ci[i]= (ci[i-1]*c)%P;
	}
	
	vector<int> h(31,1);
	for(int t=30;t>0;t--) h[t]=dfs(t,1);

	vector<int> lp(n+1,0),num(n+1,0);
	for(int i=2;i<=n;i++){
		if(lp[i]==0)
		{
			for(int j=i;j<=n;j+=i)
			{
				if(lp[j]==0)
				lp[j]=i;
			}
		}
		num[i]=num[i/lp[i]]+1;
	}
	
	int end=0;
	for(int i=1;i<=n;i++){
		end= (end+h[num[i]]*ci[i])%P;
	}
	cout <<end<<'\n';
}
signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}
