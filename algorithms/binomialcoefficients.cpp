#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll binpow(ll a, ll p)
{
    ll res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res * (a % mod) % mod;
        }
        a = a % mod * (a % mod) % mod;
        p >>= 1;
    }

    return res % mod;
}

int main()
{
    ll n;
    vector<ll> v(1'000'000);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 0; i <= 1'000'000; ++i) {
        if (!i) {
            v[i] = 1;
        }
        else {
            v[i] = v[i - 1] % mod * (i % mod) % mod; 
        }
    }
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << v[a] * binpow(v[a - b] * v[b] % mod, mod - 2) % mod << "\n";
    }
}