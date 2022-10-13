#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    ll ans = 0;
    vector<ll> vals, d(5), f(5);
    d[4] = 9, d[3] = 2, d[2] = 1;
    f[4] = 24, f[3] = 6, f[2] = 2, f[1] = 1, f[0] = 1;
    for (ll j = n - k; j < n - 1; ++j) {
        ll based = 1;
        for (ll i = j + 1; i <= n; ++i) {
            based *= i;
        }
        based /= f[n - j];
        ans += based * d[n - j];
    }
    cout << ans + 1;
}