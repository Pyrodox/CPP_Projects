#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

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
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll ans = 0;
    for (ll i = 0; i <= 2 * n; ++i) {
        ans = (ans + binpow(2, i)) % mod;
    }
    cout << ans;
}