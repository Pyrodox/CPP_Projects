#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const ll mx = 2e5 + 1;

vector<ll> f(mx), inv(mx);

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

void factorial()
{
    f[0] = 1;
    for (ll i = 1; i < mx; ++i) {
        f[i] = f[i - 1] * i % mod;
    }
}

void invfactorial()
{
    inv[0] = 1;
    for (ll i = 1; i < mx; ++i) {
        inv[i] = binpow(f[i], mod - 2);
    }
}

ll comb(ll n, ll r)
{
    return f[n] * inv[r] % mod * inv[n - r] % mod;
}

int main()
{
    ll n, q, m, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    factorial();
    invfactorial();
    cout << inv[5];
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        cin >> n >> m >> k;
        vector<ll> v(n);
        map<ll, ll> duplicateamt;
        for (ll j = 0; j < n; ++j) {
            cin >> v[j];
            duplicateamt[v[j]]++;
        }
        sort(v.begin(), v.end());
        ll ans = 0, l = 0, r = 0;
        while (n - l >= m) {
            r = upper_bound(v.begin() + l, v.end(), v[l] + k) - v.begin();
            if (r - l >= m) {
                ans = (ans + comb(r - l, m)) % mod;
            }
            if (r - l - m >= duplicateamt[v[l]]) {
                ans = (ans - comb(r - l - duplicateamt[v[l]], m)) % mod;
            }
            l += duplicateamt[v[l]]; 
        }
        cout << (ans + mod) % mod << "\n";
    }
}