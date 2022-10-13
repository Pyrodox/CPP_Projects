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
    vector<ll> dp(n + 1);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
    for (ll i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 2] + abs(v[i] - v[i - 2]), dp[i - 1] + abs(v[i] - v[i - 1]));
    }
    cout << dp[n - 1];
}