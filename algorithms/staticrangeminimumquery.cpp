#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 2e5 + 1, LOG = 17;

vector<vector<ll>> m(mx, vector<ll>(LOG + 1));

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        m[i + 1][0] = v[i];
    }
    for (ll i = 1; i <= LOG; ++i) {
        for (ll j = 1; j <= n - (1 << i) + 1; ++j) {
            m[j][i] = min(m[j][i - 1], m[j + (1 << (i - 1))][i - 1]);
        }
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll length = r - l + 1;
        length = log(length) / log(2);
        cout << min(m[l][length], m[r + 1 - (1 << length)][length]) << "\n";
    }
}