#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, maxval = 0, maxvalr = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<ll>> v(m + 1);
    vector<ll> availleft(m + 1), availright(m + 1);
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        ++availleft[a];
        ++availright[b];
        maxval = max(maxval, a);
        maxvalr = max(maxvalr, b);
        v[a].push_back(b);
    }
    vector<ll> ans(1000000);
    for (ll i = 0; i <= maxval; ++i) {
        if (availleft[i]) {
            for (ll j = i; j <= maxval; ++j) {
                if (availleft[j] && i != j) {
                    ans[i + j] += 2 * (availleft[i] * availleft[j]);
                }
                if (i == j) {
                    ans[i + j] += availleft[i] * (availleft[j]);
                }
            }
        }
    }
    for (ll i = 0; i <= maxvalr; ++i) {
        if (availright[i]) {
            for (ll j = i; j <= maxvalr; ++j) {
                if (availright[j] && i != j) {
                    ans[i + j + 1] -= 2 * (availright[i] * availright[j]);
                }
                if (i == j) {
                    ans[i + j + 1] -= availright[i] * (availright[j]);
                }
            }
        }
    }
    for (ll i = 1; i <= 2 * m + 1; ++i) {
        ans[i] += ans[i - 1];
    }
    for (ll i = 0; i < 2 * m + 1; ++i) {
        cout << ans[i] << "\n";
    }
}