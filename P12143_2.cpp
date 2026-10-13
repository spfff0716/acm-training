#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    int l = 0;        // 左指针
    int bad = 0;      // 窗口内不合法的相邻对数（断层数）
    
    for (int r = 0; r < n; r++) {
        // 右指针扩展，检查是否和前一个形成断层
        if (r > 0) {
            int d = s[r] - s[r-1];
            if (d != 0 && d != 1) bad++;
        }
        
        // 如果断层超过1，收缩左指针
        while (bad > 1) {
            int d = s[l+1] - s[l];
            if (d != 0 && d != 1) bad--;
            l++;
        }
        
        // 以 r 结尾的合法子串数量 = 窗口长度
        ans += r - l + 1;
    }
    
    cout << ans << endl;
    return 0;
}
