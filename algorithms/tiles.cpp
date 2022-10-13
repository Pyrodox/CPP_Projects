#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

ll binpow(ll x, ll p)
{
    ll res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res % mod * (x % mod) % mod;
        }
        x = x % mod * (x % mod) % mod;
        p >>= 1;
    }

    return res % mod;
}

int main()
{
    ll w, h;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w >> h;
    cout << binpow(2, w + h);
}