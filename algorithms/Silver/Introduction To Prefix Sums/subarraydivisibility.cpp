#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    map<ll, ll> present;
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    ll ans = 0;
    present[0]++;
    for (ll i = 1; i <= n; ++i) {
        present[(v[i] % n + n) % n]++;
    }
    for (auto a : present) {
        ans += (a.second * (a.second - 1)) / 2;
    }
    cout << ans;
}