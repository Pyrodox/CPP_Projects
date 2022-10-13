#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    vector<ll> pref(n + 1), suf(n + 2);
    for (ll i = 1; i < n; ++i) {
        if (v[i + 1] < v[i]) {
            pref[i] += abs(v[i + 1] - v[i]);
        }
        pref[i] += pref[i - 1];
    }
    pref[n] = pref[n - 1];
    for (ll i = n; i > 1; --i) {
        if (v[i - 1] < v[i]) {
            suf[i] += abs(v[i - 1] - v[i]);
        }
        suf[i] += suf[i + 1];
    }
    suf[1] = suf[2];
    while (m--) {
        ll a, b;
        cin >> a >> b;
        if (a < b) {
            cout << pref[b - 1] - pref[a - 1] << "\n";
        }
        else {
            cout << suf[b + 1] - suf[a + 1] << "\n";
        }
    }
}