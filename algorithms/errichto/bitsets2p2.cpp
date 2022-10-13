#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, w;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    bitset<10000001> bt;
    bt[0] = 1;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        bt |= bt << x;
    }
    bt[w] ? cout << "YES" : cout << "NO";
}