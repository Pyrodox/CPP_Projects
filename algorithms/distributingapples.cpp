#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll binpow(ll a, ll p)
{
    a %= mod;
    ll res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res * a % mod; 
        }
        a = a * a % mod;
        p >>= 1;
    }

    return res;
}

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    ll top = 1;
    for (ll i = 2; i <= n + m - 1; ++i) {
        top = top * i % mod;
    }
    ll bot = 1;
    for (ll i = 2; i <= m; ++i) {
        bot = bot * i % mod;
    }
    for (ll i = 2; i <= n - 1; ++i) {
        bot = bot * i % mod;
    }
    cout << top * binpow(bot, mod - 2) % mod;
}