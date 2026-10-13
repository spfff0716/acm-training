#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    const int MOD = 10000;
    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (N == 2) {
        cout << 2 << endl;
        return 0;
    }
    // N >= 3 时使用滚动变量（只需保留最近 3 个值）
    long long prev3 = 1; // a[0]
    long long prev2 = 1; // a[1]
    long long prev1 = 2; // a[2]
    for (int i = 3; i <= N; ++i) {
        long long curr = (2LL * prev1 + prev3) % MOD;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1 << endl;
    return 0;
}
