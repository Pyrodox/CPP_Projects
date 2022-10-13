#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

ll binpow(ll x, ll y)
{
    ll ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret = ret % mod * (x % mod) % mod;
        }
        x = x % mod * (x % mod) % mod;
        y >>= 1;
    }

    return ret % mod;
}

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    map<ll, ll> amt;
    vector<vector<ll>> v(n);
    for (ll i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; ++j) {
            ll a;
            cin >> a;
            amt[a]++;
            v[i].push_back(a);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < v.size(); ++i) {
        ll avail = 0;
        for (ll j = 0; j < v[i].size(); ++j) {
            avail += amt[v[i][j]];
        }
        ans = ans % mod + ((avail % mod * (binpow((n % mod * (n % mod) % mod) * (v[i].size() % mod) % mod, mod - 2) % mod) % mod) % mod) % mod;
    }
    cout << ans % mod;
}