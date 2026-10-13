#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        map<long long, int> freq;
        long long cur = 1;
        vector<long long> ans;
        
        for (int i = 0; i < n; ++i) {
            long long s = a[i];
            int old = freq[s];
            long long mul = m - old;
            if (mul <= 0) {
                cur = 0;
            } else if (cur != 0) {
                cur = cur * mul % MOD;
            }
            freq[s]++;
            ans.push_back(cur);
        }
        
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
