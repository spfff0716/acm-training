#include <bits/stdc++.h>
using namespace std;

/* 返回下标；找不到返回 -1 */
int search(int i, int j, const vector<array<int,2>>& a) {
    for (size_t k = 0; k < a.size(); ++k)
        if (a[k][0] == i && a[k][1] == j) return (int)k;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    cin.ignore();   // 吃掉 '\n'

    vector<array<int,2>> a;   // (i,j)
    vector<int> key;          // k

    enum { FIELD_N = 5 };
    for (int x = 0; x < q; ++x) {
        int back[FIELD_N] = {0};
        string line;
        getline(cin, line);
        stringstream ss(line);
        int cnt = 0;
        while (cnt < FIELD_N && ss >> back[cnt]) ++cnt;

        int i = back[1], j = back[2], k = back[3];
        if (back[0] == 1) {
            a.push_back({i, j});
            key.push_back(k);
        }
        if (back[0] == 2) {
            int need = search(i, j, a);
            if (need != -1) cout << key[need] << '\n';
        }
    }
    return 0;
}

