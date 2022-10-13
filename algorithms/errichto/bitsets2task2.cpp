#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x;
    cout << (1 << (32 - __builtin_clz(x))); 
}