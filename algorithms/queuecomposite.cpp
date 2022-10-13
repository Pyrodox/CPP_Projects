#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

ll binpow(ll a, ll p)
{
    ll res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res % mod * (a % mod) % mod;
        }
        a = a % mod * (a % mod) % mod;
        p >>= 1;
    }

    return res % mod;
}

int main()
{
    ll q, a = 1, b = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    vector<pair<ll, ll>> que;
    ll iter = 0;
    while (q--) {
        ll q0;
        cin >> q0;
        if (!q0) {
            ll slope, base;
            cin >> slope >> base;
            que.push_back({slope, base});
            b = (base % mod + (slope % mod * (b % mod) % mod)) % mod;
            a = a % mod * (slope % mod) % mod;
        }
        else if (q0 == 1) {
            a = a % mod * binpow(que[iter].first, mod - 2) % mod;
            b = (b % mod - (a % mod * (que[iter].second % mod) % mod)) % mod;
            if (b < 0) {
                b += mod;
            }
            ++iter;
        }
        else {
            ll x;
            cin >> x;
            if (iter < que.size()) {
                cout << (a % mod * (x % mod) % mod + b % mod) % mod << "\n";
            }
            else {
                cout << x % mod << "\n";
            }
        }
    }
}