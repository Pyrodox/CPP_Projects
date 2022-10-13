#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mx = 1e5, LOG = 16;

vector<vector<ll>> m(mx, vector<ll>(LOG + 1));

int main()
{
    ll n, q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        m[i][0] = v[i];
    }
    for (ll i = 1; i <= LOG; ++i) {
        for (ll j = 0; j <= n - (1 << i); ++j) {
            m[j][i] = min(m[j][i - 1], m[j + (1 << (i - 1))][i - 1]);
        }
    }
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll length = r - l + 1;
        length = log(length) / log(2);
        cout << min(m[l][length], m[r + 1 - (1 << length)][length]) << "\n";
    }
}