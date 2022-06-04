#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    map<ll, ll> present;
    present[0] = 1;
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ans += present[v[i] - x];
        present[v[i]]++;
    }
    cout << ans;
}