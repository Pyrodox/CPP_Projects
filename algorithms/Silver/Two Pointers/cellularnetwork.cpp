#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, ans = 0;
    ll dist[100000];
    for (ll i = 0; i < 100000; ++i) {
        dist[i] = 2 * 1000000007;
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    ll c1 = 0;
    for (ll i = 0; i < n; ++i) {
        while (c1 < (m - 1) && b[c1 + 1] <= a[i]) {
            ++c1;
        }
        dist[i] = min(dist[i], abs(a[i] - b[c1]));
    }
    c1 = m - 1;
    for (ll i = n - 1; i >= 0; --i) {
        while (c1 > 0 && b[c1 - 1] >= a[i]) {
            --c1;
        }
        dist[i] = min(dist[i], abs(a[i] - b[c1]));
    }
    for (ll i = 0; i < n; ++i) {
        ans = max(ans, dist[i]);
    }
    cout << ans;
}