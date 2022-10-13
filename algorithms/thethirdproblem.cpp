#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

ll factorial(ll n)
{
    if (!n) {
        return 1;
    }
    ll ret = 1;
    for (ll i = 1; i <= n; ++i) {
        ret *= i % MOD;
        ret %= MOD;
    }

    return ret;
}

int main()
{
    ll n, t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> v(n), v2(n);
        for (ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            v2[i] = a;
            v[a] = i;
        }
        ll ans = 1, left = min(v[0], v[1]), right = max(v[0], v[1]);
        for (ll i = 2; i < max(v2[0], v2[n - 1]); ++i) {
            if (v[i] <= right && v[i] >= left) {
                ans *= (right - left + 1 - i) % MOD;
            }
            left = min(left, v[i]);
            right = max(right, v[i]);
        }
        cout << (ans * (max((ll)1, factorial((n - 1 - max(v2[0], v2[n - 1])))) % MOD)) % MOD << "\n";
    }
}