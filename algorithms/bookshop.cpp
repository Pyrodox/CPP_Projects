#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b)
{
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main()
{
    ll n, x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        v.push_back({a, 0});
    }
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        v[i].second = a;
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = 0;
    vector<ll> dp(x + 2);
    for (ll i = 0; i < n; ++i) {
        for (ll j = x - v[i].first; j >= 0; --j) {
            dp[j + v[i].first] = max(dp[j + v[i].first], v[i].second + dp[j]);
            ans = max(ans, dp[j + v[i].first]);
        }
    }
    cout << ans;
}