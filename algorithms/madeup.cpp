#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    unordered_map<ll, ll> u;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
        u[c[i]]++;
    }
    unordered_map<ll, ll> u2;
    for (ll i = 0; i < n; ++i) {
        u2[b[i]] += u[i + 1];
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += u2[a[i]];
    }
    cout << ans;
}