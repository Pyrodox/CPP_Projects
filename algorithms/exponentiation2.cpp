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

ll binpow2(ll x, ll p)
{
    ll res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res % (mod - 1) * (x % (mod - 1)) % (mod - 1);
        }
        x = x % (mod - 1) * (x % (mod - 1)) % (mod - 1);
        p >>= 1;
    }

    return res % (mod - 1);
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow2(b, c) % (mod - 1)) << "\n";
    }
}