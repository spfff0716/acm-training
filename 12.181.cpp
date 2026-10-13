#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 3000; // 足够大的数组大小
int res[N], base[N], temp[N];

void multi1() {
    memset(temp, 0, sizeof(temp));
    int carry = 0;
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            temp[i + j] += res[i] * base[j];
        }
    }
    for (int i = 0; i < 1000; i++) { // 确保数组大小足够
        temp[i] += carry;
        res[i] = temp[i] % 10;
        carry = temp[i] / 10;
    }
}

void multi2() {
    memset(temp, 0, sizeof(temp));
    int carry = 0;
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            temp[i + j] += base[i] * base[j];
        }
    }
    for (int i = 0; i < 1000; i++) { // 确保数组大小足够
        temp[i] += carry;
        base[i] = temp[i] % 10;
        carry = temp[i] / 10;
    }
}

void pow(int n) {
    while (n > 0) {
        if (n & 1) {
            multi1();
        }
        multi2();
        n >>= 1;
    }
}

int main() {
    int p;
    cin >> p;
    int m = 1;
    int digits = floor(p * log10(2)) + 1; // 计算位数
    cout << digits << endl;

    res[0] = 1; // 初始化结果为 1
    base[0] = 2; // 初始化基数为 2
    pow(p);

    int k = digits - 1; // 从最高位开始输出
    while (k >= 0) {
        cout << res[k];
        k--;
    }
    cout << endl;

    return 0;
}

