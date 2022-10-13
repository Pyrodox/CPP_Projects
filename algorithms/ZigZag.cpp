#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<pair<ll, ll>> seq(n + 1);
    for (ll i = 0; i < n; ++i) {
        seq[i].second = 1001;
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= min(ans, i); ++j) {
            if (seq[j].first > v[i] || !j) {
                ans = max(ans, j + 1);
                seq[j + 1].second = min(seq[j + 1].second, v[i]);
            }
            if (seq[j].second < v[i] || !j) {
                ans = max(ans, j + 1);
                seq[j + 1].first = max(seq[j + 1].first, v[i]);
            }
        }
    }
    cout << ans;
}