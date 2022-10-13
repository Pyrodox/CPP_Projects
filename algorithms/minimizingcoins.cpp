#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, amt;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> amt;
    vector<ll> dp(1000001), coins;
    dp[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        coins.push_back(a);
        dp[a] = 1;
    }
    for (ll i = 1; i <= amt; ++i) {
        dp[i] = 1000000000;
        for (ll j = 0; j < n; ++j) {
            if (i >= coins[j]) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if (dp[amt] == 1000000000) {
        cout << -1;
        return 0;
    }
    cout << dp[amt];
}