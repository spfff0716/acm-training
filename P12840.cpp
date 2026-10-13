#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long p(int n)
{
    long long carry = 2;
    long long res = 1;
    while(n > 0)
    {
        if(n & 1) res = res * carry % mod;
        carry = carry * carry % mod;
        n >>= 1;
    }
    return res;
}

long long f(int left,int right,int l,int r,int leave)
{
    // ? 必须加：终止条件
    if(leave == 0) return 1;

    long long sum = 1;

    if(l == left || r == right)
    {
        sum = sum * p(left - 1) % mod;
        // ? 这里也要消耗步数！否则无限递归
        sum = sum * f(left, right, l, r, leave - 1) % mod;
    }
    else if(left == 2)
    {
        sum = sum * 2 % mod;
        // ? 这里也要走下一步
        sum = sum * f(left, right, l, r, leave - 1) % mod;
    }
    else if(l - left == 1)
    {
        sum = sum * 3 % mod;
        sum = sum * f(left+1, right, l, r, leave-1) % mod;
        sum = sum * f(left, right-1, l, r, leave-1) % mod;
        sum = sum * f(left, right, l, r+1, leave-1) % mod;
    }
    else if(right - r == 1)
    {
        sum = sum * 3 % mod;
        sum = sum * f(left+1, right, l, r, leave-1) % mod;
        sum = sum * f(left, right, l-1, r, leave-1) % mod;
        sum = sum * f(left, right-1, l, r, leave-1) % mod;
    }
    else
    {
        sum = sum * 4 % mod;
        sum = sum * f(left+1, right, l, r, leave-1) % mod;
        sum = sum * f(left, right, l-1, r, leave-1) % mod;
        sum = sum * f(left, right-1, l, r, leave-1) % mod;
        sum = sum * f(left, right, l, r+1, leave-1) % mod;
    }

    return sum;
}

int main()
{
    long long r = 0;
    // 注意：2024 规模跑不出来，只能测试小范围如 i<=5
    for(int i=2; i<=5; i++)
    {
        r = (r + f(1, 2025, i, i, 2022)) % mod;
    }
    cout << r << endl;
    return 0;
}
